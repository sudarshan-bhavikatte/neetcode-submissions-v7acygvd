class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;

        int res = 0;

        while(r < nums.size() - 1){
            int fartest = 0;
            for(int i = l; i <= r; i++){
                fartest = max(fartest, i + nums[i]);
            }
            l = r + 1;
            r = fartest;
            res++;
        }

        return res;
    }
};
