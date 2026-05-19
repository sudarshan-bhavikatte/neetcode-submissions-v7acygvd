class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> v(rows, vector<bool>(cols, false));

        queue<pair<int, int>> q;

        int dis = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0)q.push({i, j});
            }
        }

        while(!q.empty()){
            int size = q.size();

            while(size > 0){
                size--; 
                auto [r, c] = q.front(); q.pop();

                if(v[r][c]) continue;
                v[r][c] = true;
                grid[r][c] = dis;
                if(r > 0 && grid[r - 1][c] != -1)q.push({r - 1, c});
                if(r < rows - 1 && grid[r + 1][c] != -1)q.push({r + 1, c});

                if(c > 0 && grid[r][c - 1] != -1)q.push({r, c - 1});
                if(c < cols - 1 && grid[r][c + 1] != -1)q.push({r, c + 1});
            }
            dis++;
        }
    }
};
