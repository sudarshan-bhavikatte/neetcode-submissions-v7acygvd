class Solution {
public:

    void dfs(vector<int>& nums, int i, int sum, int target, vector<int>& subset,
        vector<vector<int>>& res
    ){
        if(i >= nums.size() || sum > target) return;

        if(sum == target){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i, sum + nums[i], target, subset, res);
        
        subset.pop_back();
        dfs(nums, i+1, sum, target, subset, res);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;

        dfs(nums, 0, 0, target, subset, res);

        return res;
    }
};
