class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        for(int num : nums)hash[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

        auto it = hash.begin();

        while(it != hash.end()){
            pq.push({it->second, it->first});
            it++;
        }

        vector<int> res(k);

        for(int i = 0; i < k; i++){
            res[i] = pq.top().second;
            pq.pop();
        }

        return res;
    }
};
