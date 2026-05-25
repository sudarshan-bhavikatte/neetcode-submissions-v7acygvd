class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }

        int res = INT_MIN;

        for(int i = 0; i < n; i++){
            int currSum = 0;
            for(int j = i; j < i + n; j++){
                if(currSum < 0)currSum = 0;
                currSum += nums[j];

                res = max(currSum, res);
            }
        }

        return res;        
    }
};