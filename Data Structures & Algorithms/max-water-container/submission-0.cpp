class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;

        int i = 0;
        int j = heights.size()-1;

        while(i<j){
            cout << std::min(heights[i],heights[j]) << " * " << (j-i) <<endl;
            int area = std::min(heights[i],heights[j]) * (j-i);
            maxArea = std::max(maxArea, area);

            if(heights[i] <= heights[j])i++;
            else j--;
        }
        return maxArea;
    }
};
