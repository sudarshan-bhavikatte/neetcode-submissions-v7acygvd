class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cmp = [&](const int a, const int b){
            if(abs(a - x) == abs(b - x))return a < b;
            else return abs(a - x) < abs(b - x);
        };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for(int i = 0; i < arr.size(); i++){
            pq.push(arr[i]);
            if(pq.size() > k)pq.pop();
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top()); pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};