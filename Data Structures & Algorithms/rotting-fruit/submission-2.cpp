class Solution {

private:
    int ROWS;
    int COLS;
    vector<vector<bool>> V;
    queue<pair<int, int>> Q;

    void helper(int r, int c, vector<vector<int>>& grid){
        if(
            r < 0 ||
            c < 0 ||
            r >= ROWS ||
            c >= COLS ||
            grid[r][c] == 0 ||
            V[r][c]
        ) return;

        V[r][c] = true;
        Q.push({r, c});
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        V.assign(ROWS, vector<bool>(COLS, false));

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(grid[i][j] == 2){
                    Q.push({i,j});
                    V[i][j] = true;
                }
            }
        }

        

        int time = 0;

        while(!Q.empty()){
            int size = Q.size();

            for(int i = 0; i < size; i++){
                auto [r,c] = Q.front(); Q.pop();
                V[r][c] = true;

                helper(r + 1, c, grid);
                helper(r - 1, c, grid);
                helper(r, c + 1, grid);
                helper(r, c - 1, grid);
            }

            time++;
        }

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(grid[i][j] == 1 && !V[i][j]){
                    return -1;
                }
            }
        }
        return time == 0 ? time : time -1;
    }
};
