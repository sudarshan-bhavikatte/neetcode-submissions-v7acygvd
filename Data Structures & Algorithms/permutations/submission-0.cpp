class Solution {

private:
    void helper(
        vector<int>& nums,
        int index,
        vector<vector<int>>& res
    ) {
        if( index == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            helper(nums, index+1,res);
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        helper(nums, 0, res);

        return res;
    }
};
