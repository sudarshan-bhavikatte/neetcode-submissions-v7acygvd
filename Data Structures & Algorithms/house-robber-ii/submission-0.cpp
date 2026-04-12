class Solution {

private:
    int helper(int s, int n, vector<int>& nums){

        int first = nums[s];
        int second = max(nums[s], nums[s + 1]);

        for(int i = s + 2; i < n; i++){
            int curr = max(second, nums[i] + first);
            first = second;
            second = curr;
        }

        return max(first, second);
    }

public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 0)return 0;
        if(n == 1)return nums[0];

        return max(helper(1, n, nums), helper(0, n - 1, nums));

    }
};
