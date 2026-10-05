class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = INT_MIN;

        int l = 0;
        int r = heights.size() - 1;

        while(l < r){
            int h = min(heights[l], heights[r]);
            int area = h * (r - l);
            res = max(res, area);
            if(heights[l] <= heights[r])l++;
            else r--;
        }

        return res;
    }
};
