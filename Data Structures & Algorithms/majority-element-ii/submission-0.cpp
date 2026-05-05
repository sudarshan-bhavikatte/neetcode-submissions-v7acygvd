class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size() / 3;
        for(int n : nums)hash[n]++;

        vector<int> res;

        for(auto it = hash.begin(); it != hash.end(); it++){
            if(it->second > n){
                res.push_back(it->first);
            }
        }

        return res;
    }
};