class Solution {
    void dfs(vector<int>& nums, int i,int target, vector<int>&subset, vector<vector<int>>& res){
        if(target < 0)return;
        if(i >= nums.size()){
            if(target == 0){
                res.push_back(subset);
            }
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i, target - nums[i], subset, res);

        subset.pop_back();
        dfs(nums, i + 1, target, subset, res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;

        dfs(nums, 0, target, subset, res);

        return res;        
    }
};
