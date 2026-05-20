class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));

        queue<pair<int, int>> q;

        for (int j = 0; j < cols; j++) {
            q.push({0, j});
        }
        for (int i = 0; i < rows; i++) {
            q.push({i, 0});
        }

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            int h = heights[r][c];

            if (pacific[r][c]) continue;
            pacific[r][c] = true;

            if (r > 0 && heights[r - 1][c] >= h) q.push({r - 1, c});
            if (r < rows - 1 && heights[r + 1][c] >= h) q.push({r + 1, c});
            if (c > 0 && heights[r][c - 1] >= h) q.push({r, c - 1});
            if (c < cols - 1 && heights[r][c + 1] >= h) q.push({r, c + 1});
        }

        for (int j = 0; j < cols; j++) {
            q.push({rows - 1, j});
        }
        for (int i = 0; i < rows; i++) {
            q.push({i, cols - 1});
        }

        while (!q.empty()) {
            auto [r, c] = q.front();q.pop();
            int h = heights[r][c];

            if (atlantic[r][c]) continue;
            atlantic[r][c] = true;

            if (r > 0 && heights[r - 1][c] >= h) q.push({r - 1, c});
            if (r < rows - 1 && heights[r + 1][c] >= h) q.push({r + 1, c});
            if (c > 0 && heights[r][c - 1] >= h) q.push({r, c - 1});
            if (c < cols - 1 && heights[r][c + 1] >= h) q.push({r, c + 1});
        }

        vector<vector<int>> res;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(atlantic[i][j] && pacific[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};
