class Solution {
    int ROWS;
    int COLS;

    int dfs(vector<vector<int>>& grid, int r, int c){
        if(
            r < 0 ||
            c < 0 ||
            r >= ROWS ||
            c >= COLS ||
            grid[r][c] != 1
        ) return 0;

        grid[r][c] = 0;

        int area = 1;

        area += dfs(grid, r ,c + 1);
        area += dfs(grid, r - 1,c);
        area += dfs(grid, r,c - 1);
        area += dfs(grid, r + 1,c);

        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        int res = 0;

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(grid[i][j] == 1)res = max(res, dfs(grid, i, j));
            }
        }
        return res;    
    }
};
