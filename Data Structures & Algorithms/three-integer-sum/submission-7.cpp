class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res_set;
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i- 1] == nums[i]) continue;
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    res_set.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if (sum < 0)l++;
                else r--;
            }
        }

        return vector<vector<int>>(res_set.begin(), res_set.end());
    }
};
