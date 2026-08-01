class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st; // {startIndex, height}
        int res = 0;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            while (!st.empty() && st.top().second > heights[i]) {
                res = max(res,
                          (i - st.top().first) * st.top().second);
                start = st.top().first;
                st.pop();
            }

            st.push({start, heights[i]});
        }

        while (!st.empty()) {
            res = max(res,
                      (int)(heights.size() - st.top().first) * st.top().second);
            st.pop();
        }

        return res;
    }
};