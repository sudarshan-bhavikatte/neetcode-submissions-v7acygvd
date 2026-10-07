class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int currSum = 0;
            for(int j = i; j < nums.size(); j++){
                currSum += nums[j];
                if(currSum >= target){
                    res = min(res, (j - i + 1));
                }
            }
        }

        return (res == INT_MAX) ? 0 : res;
    }
};