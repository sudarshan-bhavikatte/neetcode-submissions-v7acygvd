class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // collect rotten oranges and count fresh
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0) return 0;

        int time = 0;

        while(!q.empty()) {
            int size = q.size();
            bool rotted = false;

            while(size--) {
                auto [r, c] = q.front();
                q.pop();

                vector<pair<int,int>> dir = {
                    {1,0}, {-1,0}, {0,1}, {0,-1}
                };

                for(auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if(nr >= 0 && nc >= 0 &&
                       nr < rows && nc < cols &&
                       grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                        rotted = true;
                    }
                }
            }

            if(rotted) time++;
        }

        return fresh == 0 ? time : -1;
    }
};