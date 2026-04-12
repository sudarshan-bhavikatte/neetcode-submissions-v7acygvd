class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0];

        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i];
            max = std::max(max, curr);
            for(int j = i + 1; j < nums.size(); j++){
                curr *= nums[j];
                max = std::max(max, curr);
            }
        }

        return max;
    }
};
