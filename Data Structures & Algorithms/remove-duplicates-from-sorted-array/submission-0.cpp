class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0;

        while(l < nums.size()){
            int r = l;
            while(r < nums.size() && nums[l] == nums[r])r++;
            if(r != l){
                nums.erase(nums.begin() + l + 1, nums.begin() + r);
            }
            l++;
        }

        return nums.size();
    }
};