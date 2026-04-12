class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;
        vector<int> new_nums;

        for(int n : nums){
            if(n == val){
                count++;
            }
            else {
                new_nums.push_back(n);
            }
        }

        for(int i = 0; i < new_nums.size(); i++){
            nums[i] = new_nums[i];
        }

        for(int i = count ; i > 0; i--){
            nums.pop_back();
        }
        return n - count;
    }
};