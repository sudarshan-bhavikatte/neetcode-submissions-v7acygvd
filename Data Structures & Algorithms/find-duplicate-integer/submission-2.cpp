class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> marked(nums.size(), false);

        for(int n : nums){
            if(marked[n - 1] == true) return n;
            marked[n - 1] = true;
        }
    }
};
