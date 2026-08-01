class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int l_max = INT_MIN;
        int r_max = INT_MIN;

        int res = 0;
        while(i < j){
            l_max = max(height[i], l_max);
            r_max = max(height[j], r_max);

            if(l_max < r_max){
                res += (l_max - height[i]);
                i++;
            } else {
                res += (r_max - height[j]);
                j--;
            }
        }

        return res;
    }
};
