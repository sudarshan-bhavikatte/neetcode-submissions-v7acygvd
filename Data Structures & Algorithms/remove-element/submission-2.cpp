class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                res.push_back(nums[i]);
            }
        }
        int idx = 0;
        for(int n : res){
            nums[idx++] = n;
        }

        return idx;
    }
};