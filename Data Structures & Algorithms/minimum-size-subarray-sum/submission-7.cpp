class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int l = 0;
        int currSum = 0;

        for(int r = 0; r < nums.size(); r++){
            currSum += nums[r];

            while(currSum >= target){
                res = min(res, r - l + 1);
                currSum -= nums[l];
                l++;
            }
        }

        return (res == INT_MAX) ? 0 : res;
    }
};