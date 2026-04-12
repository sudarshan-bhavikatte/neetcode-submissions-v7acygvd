class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)return 0;
        int res = 0;
        int i = 0, j = height.size() - 1;
        int leftMax = height[i], rightMax = height[j];

        while(i<j){
            if(height[i] < height[j]){
                leftMax = max(leftMax,height[i]);
                res += leftMax - height[i];
                i++;
            }
            else {
                rightMax = max(rightMax,height[j]);
                res += rightMax - height[j];
                j--;
            }
        }
        return res;
    }
};
