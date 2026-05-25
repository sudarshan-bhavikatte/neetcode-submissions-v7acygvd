class Solution {
    bool helper(vector<int>& nums, int i){
        if(i >= nums.size())return false;
        if(i == nums.size() - 1){
            return true;
        }
        if(nums[i] == 0) return false;
        int steps = nums[i];

        while(steps > 0){
            if(helper(nums, i + steps)){
                return true;
            }
            steps--;
        }

        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        return helper(nums, 0);
    }
};
