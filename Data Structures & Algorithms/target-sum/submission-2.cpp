class Solution {
private:
    int dfs(int i, int sum, int target, vector<int>& nums){
        if(i == nums.size()){
            if(target == sum)return 1;
            return 0;
        }

        int sub = dfs(i+1, sum - nums[i], target,  nums);
        int add = dfs(i+1, sum + nums[i], target, nums);

        return add + sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, 0, target, nums);
    }
};
