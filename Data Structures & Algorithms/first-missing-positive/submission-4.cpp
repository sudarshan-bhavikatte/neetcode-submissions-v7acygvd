class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] < 0)nums[i] = 0;
        }

        for(int i = 0; i < n; i++){
            int val = abs(nums[i]);

            if(1 <= val && val <= n){
                if(nums[val - 1] > 0)nums[val - 1] *= -1;
                else if(nums[val - 1] == 0)nums[val - 1] = -1 * (n + 1);
            }
        }

        for(int i = 1; i <= n; i++){
            if(nums[i - 1] >= 0)return i;
        }

        return n + 1;
    }
};