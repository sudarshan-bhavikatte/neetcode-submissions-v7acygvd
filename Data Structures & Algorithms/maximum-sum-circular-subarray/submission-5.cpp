class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0];
        int minSum = nums[0];
        
        int total = 0;
        int currMax = 0;
        int currMin = 0;
        for(int i = 0; i < nums.size(); i++){
            currMax = max(currMax + nums[i], nums[i]);
            currMin = min(currMin + nums[i], nums[i]);

            total += nums[i];

            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }
        
        return (maxSum > 0) ? max(maxSum, total - minSum) : maxSum;
    }
};