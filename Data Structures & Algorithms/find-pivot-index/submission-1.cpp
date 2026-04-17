class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>prefix_sum(nums.size(), 0);
        vector<int>postfix_sum(nums.size(), 0);

        int total = 0;

        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            prefix_sum[i] = total;
        }

        total = 0;

        for(int i = nums.size() - 1; i >= 0; i--){
            total += nums[i];
            postfix_sum[i] = total;
        }

        for(int i = 0; i < prefix_sum.size(); i++){
            if(prefix_sum[i] == postfix_sum[i]) return i;
        }

        return -1;
    }
};