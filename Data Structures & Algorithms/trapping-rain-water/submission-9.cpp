class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int lMax = height[i];
        int rMax = height[j];

        int res = 0;
        while(i < j){
            if(lMax < rMax){
                i++;
                lMax = max(lMax, height[i]);
                res += lMax - height[i];
            } else {
                j--;
                rMax = max(rMax, height[j]);
                res += rMax - height[j];
            }
        }

        return res;
        
    }
};
