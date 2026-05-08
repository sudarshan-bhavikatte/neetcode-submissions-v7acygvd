class Solution {
public:
    int findMin(vector<int> &nums) {
        int i = 0;
        int j = nums.size() - 1;

        int min = INT_MAX;
        while(i < j){
            int m = (i + j) / 2;
            if(nums[m] > nums[j]){
                i = m + 1;
            }
            else j = m;
        }
        return nums[i];
    }
};
