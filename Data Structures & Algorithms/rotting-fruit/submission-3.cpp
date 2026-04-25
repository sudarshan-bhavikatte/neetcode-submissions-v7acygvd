class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> V;

        int fresh = 0;
        int time = 0;

        queue<vector<int>> q;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1)fresh++;
                else if(grid[i][j] == 2)q.push({i,j});
            }
        }

        vector<vector<int>> dirs = {
            {0, 1},
            {-1, 0},
            {0, -1},
            {1, 0}
        };

        while(fresh > 0 && !q.empty()){
            int len = q.size();

            for(int i = 0; i < len; i++){
                int r = q.front()[0]; int c = q.front()[1];
                q.pop();

                for(auto dir : dirs){
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if(
                        !(nr < 0 ||
                        nc < 0 ||
                        nr >= rows ||
                        nc >= cols ||
                        grid[nr][nc] == 0 ||
                        grid[nr][nc] == 2
                        )
                    ){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
