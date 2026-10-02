class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_count = 0;
        int one_count = 0;
        int two_count = 0;

        for(int num : nums){
            if (num == 0)zero_count++;
            else if (num == 1)one_count++;
            else two_count++;
        }
        int idx = 0;
        while(zero_count--)nums[idx++] = 0;
        while(one_count--)nums[idx++] = 1;
        while(two_count--)nums[idx++] = 2;

    }
};