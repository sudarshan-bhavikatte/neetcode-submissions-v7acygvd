class Solution {
    unordered_map<int, int> memo;
    int dfs(vector<int>& nums, int i, int j){
        if(memo.count(i))return memo[i];
        if(i > j)return 0;

        memo[i] = max(dfs(nums, i + 1, j), nums[i] + dfs(nums, i + 2, j)); 
        return memo[i];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 2)return *max_element(nums.begin(), nums.end());
        int rob_first = dfs(nums, 0, nums.size() - 2);
        memo.clear();

        return max(rob_first, dfs(nums, 1, nums.size() - 1)); 
    }
};
