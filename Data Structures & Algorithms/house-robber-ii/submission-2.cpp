class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int res1 = dfs(0, true, nums);
        memo.clear();
        int res2 = dfs(1, false, nums);
        return max(res1, res2);
    }

private:
    unordered_map<int, int> memo;

    int dfs(int i, bool flag, vector<int>& nums) {
        if(memo.find(i) != memo.end())return memo[i];

        if (i >= nums.size() || (flag && i == nums.size() - 1))
            return 0;

        memo[i] = max(dfs(i + 1, flag, nums), nums[i] + dfs(i + 2, flag, nums));
        return memo[i];
    }
};