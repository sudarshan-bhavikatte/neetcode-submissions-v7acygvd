class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(vector<int>& nums, int i, int j){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(j) != memo[i].end()){
                return memo[i][j];
            }
        }
        if(i == nums.size())return 0;

        int res = dfs(nums, i + 1, j);

        if(j == -1 || nums[j] < nums[i]){
            res = max(res, 1 + dfs(nums, i + 1, i));
        }
        memo[i][j] = res;
        return res;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return dfs(nums, 0, -1);
    }
};
