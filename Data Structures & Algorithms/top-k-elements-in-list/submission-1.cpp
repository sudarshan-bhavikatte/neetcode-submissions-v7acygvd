class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int n : nums)count[n]++;

        auto func = [&](const pair<int, int>&a, pair<int, int>&b){
            if(b.second > a.second) return true;
            return false;
        };
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            decltype(func)
            > pq(func);
        
        for(auto it = count.begin(); it != count.end(); it++){
            pq.push({it->first, it->second});
        }
        vector<int> res;
        while(k > 0){
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return res;
    }
};
