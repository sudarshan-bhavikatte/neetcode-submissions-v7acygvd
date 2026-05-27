class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 != 0)return false;

        int need = sum / 2;

        return dfs(nums, 0, need);
    }

    bool dfs(vector<int>& nums, int i, int target){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(target) != memo[i].end()){
                return memo[i][target];
            }
        }
        if(i == nums.size()){
            return target == 0;
        }

        if(target < 0) return false;
        memo[i][target] = dfs(nums, i + 1, target) || dfs(nums, i + 1, target - nums[i]);
        return dfs(nums, i + 1, target) || dfs(nums, i + 1, target - nums[i]);
    }
};
