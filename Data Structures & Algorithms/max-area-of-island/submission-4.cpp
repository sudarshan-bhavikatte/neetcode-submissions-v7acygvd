class Solution {
    int rows;
    int cols;
    vector<vector<bool>> v;
    vector<vector<int>> grid;

    int dfs(int i, int j){
        if(i < 0 || j < 0 || i >= rows || j >= cols || v[i][j] || grid[i][j] == 0) return 0;

        v[i][j] = true;

        int res = 1;

        res += dfs(i + 1, j);
        res += dfs(i, j + 1); 
        res += dfs(i - 1, j); 
        res += dfs(i, j - 1);

        return res;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->rows = grid.size();
        this->cols = grid[0].size();
        this->grid = grid;
        v.assign(rows, vector<bool>(cols, false));

        int res = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1 && !v[i][j]){
                    res = max(dfs(i, j), res);
                }
            }
        }

        return res;
    }
};
