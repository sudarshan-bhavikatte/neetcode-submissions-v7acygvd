/*
    1. array consists of +ve nums only
    2. target is +ve
    3. return min(len of subarray) where :
        - sum(subarray) >= target
    4. default return 0;
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;

        int sum = 0;
        int L = 0;
        
        for(int R = 0; R < nums.size(); R++){
            sum += nums[R];
            while(sum >= target){
                res = min(res, R - L + 1);
                sum -= nums[L];
                L++;
            }
        }

        return (res == INT_MAX) ? 0 : res;
    }
};