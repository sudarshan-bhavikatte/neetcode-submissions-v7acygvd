class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        if(nums.size() == 2)return max(nums[0], nums[1]);
        
        vector<int> dp(nums.size() - 1, 0);

        dp[0] = nums[0];

        for(int i = 1; i < nums.size() - 1; i++){
            if(i == 1)dp[i] = max(dp[0], nums[i]);
            else dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        int res = dp.back();

        dp[0] = nums[1];

        for(int i = 1; i < nums.size() - 1; i++){
            if(i == 1)dp[i] = max(dp[0], nums[i + 1]);
            else dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + 1]);
        }
        
        return max(res, dp.back());
    }
};
