class Solution {
    int res = 0;
    unordered_map<int, int> memo;
    void helper(vector<int>& nums, int i, int sum){
        if(memo.find(i) != memo.end()) res = max(sum, memo[i]);
        if(i >= nums.size()){
            res = max(sum, res);
            return;
        }

        helper(nums, i + 2, sum + nums[i]);
        helper(nums, i + 3, sum + nums[i]);

        memo[i] = max(sum, res); 
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[n - 1] = nums[n-1];
        dp[n - 2] = nums[n-2];

        for(int i = n - 3; i >=0; i--){
            if(i == n - 3) {
                dp[i] = nums[i] + dp[n - 1];
            }
            else {
                dp[i] = nums[i] + max(dp[i + 2], dp[i + 3]);
            }
        }

        return max(dp[0], dp[1]);
    }
};
