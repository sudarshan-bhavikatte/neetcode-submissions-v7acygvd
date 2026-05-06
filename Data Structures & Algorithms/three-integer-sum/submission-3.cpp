class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            if( i > 0 && nums[i] == nums[i - 1])continue;

            int k = i + 1;
            int l = nums.size() - 1;

            while(k < l){
                int sum = nums[i] + nums[k] + nums[l];

                if(sum == 0){
                    res.push_back({nums[i], nums[k], nums[l]});
                    k++;
                    l--;
                    while(k < l && nums[k] == nums[k - 1])k++;
                }
                else if(sum < 0)k++;
                else l--;
            }
        }
        return res;
    }
};
