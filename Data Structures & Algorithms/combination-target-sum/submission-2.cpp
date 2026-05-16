class Solution {
    vector<vector<int>> res;
    int target;

    void helper(vector<int>& nums,
                vector<int>& subset,
                int i,
                int sum) {

        if(sum == target) {
            res.push_back(subset);
            return;
        }

        if(sum > target || i >= nums.size())
            return;

        subset.push_back(nums[i]);
        helper(nums, subset, i, sum + nums[i]);

        subset.pop_back();

        helper(nums, subset, i + 1, sum);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        this->target = target;

        vector<int> subset;

        helper(nums, subset, 0, 0);

        return res;
    }
};