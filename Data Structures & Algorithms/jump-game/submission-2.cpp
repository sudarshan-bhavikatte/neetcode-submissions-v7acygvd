class Solution {
    unordered_map<int, bool> memo;

    bool helper(vector<int>& nums, int i){

        if(memo.find(i) != memo.end()) return memo[i];
        if(i >= nums.size())return false;
        if(i == nums.size() - 1){
            return true;
        }
        if(nums[i] == 0) return false;
        int steps = nums[i];

        while(steps > 0){
            if(helper(nums, i + steps)){
                memo[i] = true;
                return true;
            }
            steps--;
        }
        memo[i] = false;

        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        return helper(nums, 0);
    }
};
