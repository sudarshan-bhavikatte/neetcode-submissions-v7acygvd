class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(vector<int>& nums, int i, int sum, int target){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(sum) != memo[i].end()){ 
                return memo[i][sum];
            }
        }
        if(i == nums.size()){
            if(sum == target) return 1;
            else return 0;
        }

        int add = dfs(nums, i + 1, sum + nums[i], target);
        int subtract = dfs(nums, i + 1, sum - nums[i], target);

        memo[i][sum] = add + subtract;
        return add + subtract;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        return dfs(nums, 0, 0, target);                
    }
};
