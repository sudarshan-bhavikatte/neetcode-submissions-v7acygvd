class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) hash[nums[i]]++;

        vector<int> res;

        vector<pair<int, int>> bucket;

        for(auto it = hash.begin(); it != hash.end(); it++){
            bucket.push_back({it->second, it->first});
        }
        sort(bucket.begin(), bucket.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });
        int i = 0;
        while(i < k){
            res.push_back(bucket[i].second);
            i++;
        }
        return res;
    }
};
