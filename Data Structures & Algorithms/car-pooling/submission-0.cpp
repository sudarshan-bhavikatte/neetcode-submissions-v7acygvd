class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        auto func = [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        };

        sort(trips.begin(), trips.end(), func);

        auto func2 = [](const pair<int,int>& a,
                        const pair<int,int>& b){
            return a.first > b.first; // min heap by destination
        };

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            decltype(func2)
        > pq(func2);

        int curCap = 0;

        for(int i = 0; i < trips.size(); i++) {

            int cap = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            while(!pq.empty() && pq.top().first <= from) {
                curCap -= pq.top().second;
                pq.pop();
            }

            curCap += cap;

            if(curCap > capacity)
                return false;

            pq.push({to, cap});
        }

        return true;
    }
};