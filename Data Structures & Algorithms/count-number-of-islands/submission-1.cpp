class Solution {
    int ROWS;
    int COLS;
    vector<vector<int>> V;

    void dfs(vector<vector<char>>& grid, int r, int c){
        if(
            r < 0 ||
            c < 0 ||
            r >= ROWS ||
            c >= COLS ||
            grid[r][c] != '1' ||
            V[r][c] == 1
        ) return;

        V[r][c] = 1;

        dfs(grid, r,c + 1);
        dfs(grid, r - 1,c);
        dfs(grid, r,c - 1);
        dfs(grid, r + 1,c);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        V.assign(ROWS, vector<int>(COLS, 0));

        int res = 0;

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(grid[i][j] == '1' && V[i][j] != 1){
                    dfs(grid, i, j);
                    res++;
                }
            }
        }

        return res;
    }
};
