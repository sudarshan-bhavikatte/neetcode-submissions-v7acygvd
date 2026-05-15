class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>&a, const vector<int>&b){
            return (a[0] * a[0]) + (a[1] * a[1]) > (b[0] * b[0]) + (b[1] * b[1]);
        };
        
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            decltype(comp)
        > pq(comp);

        for(auto p : points)pq.push(p);
        vector<vector<int>> res;
        while(k > 0){
            res.push_back(pq.top());
            pq.pop();
            k--;
        }

        return res;
    }
};
