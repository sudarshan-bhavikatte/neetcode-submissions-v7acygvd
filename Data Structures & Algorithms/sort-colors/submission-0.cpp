class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> color_count(3, 0);

        for(int color : nums){
            color_count[color]++;
        }
        int i = 0;
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < color_count[j]; k++){
                nums[i] = j;
                i++;
            }
        }
    }
};