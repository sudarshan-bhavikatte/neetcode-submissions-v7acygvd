class Solution {
    int rows;
    int cols;
    vector<vector<char>>grid;
    vector<vector<bool>> v;

    int dfs(int i, int j){
        if(i < 0 || j < 0 || i >= rows || j >= cols || v[i][j] || grid[i][j] == '0') return 0;

        v[i][j] = true;

        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);

        return 1;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        this->rows = grid.size();
        this->cols = grid[0].size();
        this->grid = grid;
        v.assign(rows, vector<bool>(cols, false));

        int res = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){        
                if(grid[i][j] == '1' && !v[i][j]){
                    res += dfs(i, j);
                }
            }
        }

        return res;
    }
};
