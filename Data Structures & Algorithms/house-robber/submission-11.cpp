class Solution {
    unordered_map<int, int> memo;
    int dfs(vector<int>& nums, int i){
        if(memo.count(i))return memo[i];
        if(i >= nums.size())return 0;

        memo[i] = max(nums[i] + dfs(nums, i + 2), dfs(nums, i + 1)); 
        return memo[i];
    }
public:
    int rob(vector<int>& nums) {
        return dfs(nums, 0);
    }
};
