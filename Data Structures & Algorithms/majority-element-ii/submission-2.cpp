class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count_hash;

        for(int n : nums)count_hash[n]++;

        int need = nums.size() / 3;

        vector<int> res;

        for(auto it = count_hash.begin(); it != count_hash.end(); it++){
            if(it->second > need)res.push_back(it->first);
        }

        return res;
    }
};