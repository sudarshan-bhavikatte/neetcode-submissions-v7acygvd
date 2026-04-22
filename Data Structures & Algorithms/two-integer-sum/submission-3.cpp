class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        
        for(int i = 0; i < nums.size(); i++){
            for(auto it = hash.begin(); it != hash.end(); it++){
                if(it->second == nums[i]) {
                    return {it->first, i};
                }
            }
            hash[i] = target - nums[i];
        }
        return {};
    }
};
