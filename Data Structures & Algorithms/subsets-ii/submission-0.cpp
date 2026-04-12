class Solution {

private:
    void backtrack(
        vector<int>& nums,
        int index, 
        vector<int>& subset,
        vector<vector<int>>& res
        ) {
            if (index == nums.size()){
                res.push_back(subset);
                return;
            }

            subset.push_back(nums[index]);
            backtrack(nums, index + 1, subset, res);
            subset.pop_back();

            while(
                index < nums.size() - 1 &&
                nums[index] == nums[index+1]
                ){
                    index++;
            }
            backtrack(nums, index + 1, subset, res);
        }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> subset;

        sort(nums.begin(), nums.end());

        backtrack(nums, 0, subset, res);

        return res;

    }
};
