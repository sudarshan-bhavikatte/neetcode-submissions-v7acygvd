class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) return -1;
        int path = INT_MAX;

        vector<vector<int>> V(rows, vector<int>(cols, 0));
        queue<vector<int>> q;

        q.push({0, 0, 1});
        V[0][0] = 1;

        vector<vector<int>> dirs = {{0, 1},  {-1, 1}, {-1, 0}, {-1, -1},
                                    {-1, 0}, {1, -1}, {1, 0},  {1, 1}};

        while (!q.empty()) {
            vector<int> curr = q.front();
            int r = curr[0];
            int c = curr[1];
            int len = curr[2];
            q.pop();

            if (r == rows - 1 && c == cols - 1) return len;

            for (auto dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (!(nr < 0 || nc < 0 || nr >= rows || nc >= cols || grid[nr][nc] == 1 ||
                      V[nr][nc] == 1)) {
                    V[nr][nc] = 1;
                    q.push({nr, nc, len + 1});
                }
            }
        }

        return -1;
    }
};