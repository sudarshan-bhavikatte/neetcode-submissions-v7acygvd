class Solution {
    unordered_map<int, int> memo;
    int dfs(vector<int>& nums, int target){
        if(memo.find(target) != memo.end())return memo[target];
        if(target == 0)return 1;

        int res = 0;
        for(int num : nums){
            if(target - num  >= 0){
                res += dfs(nums, target - num);
            }
            else {
                break;
            }
        }
        memo[target] = res;
        return res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return dfs(nums, target);
    }
};