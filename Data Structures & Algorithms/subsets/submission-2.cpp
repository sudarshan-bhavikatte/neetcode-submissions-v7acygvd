class Solution {
    vector<vector<int>> res;

    void helper(vector<int>& nums, vector<int> subset, int i){
        if(i >= nums.size()){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        helper(nums, subset, i + 1);
        subset.pop_back();
        helper(nums, subset, i + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> subset;
        helper(nums, subset, 0);

        return res;
    }
};
