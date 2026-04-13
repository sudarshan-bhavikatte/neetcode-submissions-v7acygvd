class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0];
        int currMaxSum = 0;

        int minSum = nums[0];
        int currMinSum = 0;

        int total = 0;

        for(int n : nums){
            currMaxSum = max(currMaxSum + n, n);
            maxSum = max(maxSum, currMaxSum);

            total += n;

            currMinSum = min(currMinSum + n, n);
            minSum = min(minSum, currMinSum);
        }

        if(maxSum < 0) return maxSum;

        return (maxSum > total - minSum) ? maxSum : total - minSum;
    }
};