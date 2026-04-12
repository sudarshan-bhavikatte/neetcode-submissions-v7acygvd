class Solution {
public:
    int ROWS;
    int COLS;
    int res;
    int area;

    void helper(int r, int c, vector<vector<int>>& grid){

        if(
            r < 0 ||
            c < 0 ||
            r >= ROWS ||
            c >= COLS ||
            grid[r][c] == 0
        ){
            return;
        }
        area++;
        grid[r][c] = 0;

        helper(r + 1, c, grid);
        helper(r - 1, c, grid);
        helper(r, c + 1, grid);
        helper(r, c - 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        res = 0;
        area = 0;
        for(int i=0; i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                helper(i,j,grid);
                if(area > res){
                    res = area;
                }
                    area = 0;
            }
        }

        return res;
    }
};
