class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;

        int l = 0;
        int r = heights.size() - 1;

        while(l < r){
            int h = min(heights[l], heights[r]);
            cout << h << " * " << r - l << endl;
            res = max(res, h * (r - l));
            
            if(heights[l] < heights[r]){
                l++;
            }
            else {
                r--;
            }
        }

        return res;
    }
};
