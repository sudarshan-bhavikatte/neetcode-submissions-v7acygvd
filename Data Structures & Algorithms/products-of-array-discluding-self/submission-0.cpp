class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;

        int prefix = 1;
        int suffix = 1;

        for (int n : nums){
            res.push_back(prefix);
            prefix *= n;
        }

        for(int i = nums.size()-1;i>=0;i--){
            res[i] *= suffix;
            suffix *= nums[i];
        }
        return res;
    }
};
