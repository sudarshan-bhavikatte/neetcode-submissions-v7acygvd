class Solution {

private:
    int ROWS;
    int COLS;

    void dfs(int r, int c, int prevH, vector<vector<int>>& heights, vector<vector<bool>>& v){

        if(
            r < 0 ||
            c < 0 ||
            r >= ROWS ||
            c >= COLS ||
            v[r][c] ||
            heights[r][c] < prevH
        ){
            return;
        }

        v[r][c] = true;
        int curr = heights[r][c];

        dfs(r + 1, c, curr, heights, v);
        dfs(r - 1, c, curr, heights, v);
        dfs(r, c + 1, curr, heights, v);
        dfs(r, c - 1, curr, heights, v);
    }


public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
    
        vector<vector<bool>> p(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> a(ROWS, vector<bool>(COLS, false));
        
        vector<vector<int>> res;

        for(int i = 0; i< ROWS; i++){
            dfs(i, 0, heights[i][0], heights, p);
            dfs(i, COLS - 1, heights[i][COLS - 1], heights, a);
        }

        for(int i = 0; i< COLS; i++){
            dfs(0, i, heights[0][i], heights, p);
            dfs(ROWS - 1, i, heights[ROWS - 1][i], heights, a);
        }

        for(int i = 0; i<ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if (p[i][j] && a[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
