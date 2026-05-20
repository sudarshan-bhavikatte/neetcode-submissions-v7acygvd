class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> v(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;

        for(int i = 0; i < rows; i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'T';
                q.push({i,0});
            }

            if(board[i][cols - 1] == 'O'){
                board[i][cols - 1] = 'T';
                q.push({i,cols - 1});
            }
        }

        for(int j = 0; j < cols; j++){
            if(board[0][j] == 'O'){
                board[0][j] = 'T';
                q.push({0,j});
            }

            if(board[rows - 1][j] == 'O'){
                board[rows - 1][j] = 'T';
                q.push({rows - 1,j});
            }
        }

        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();

            if(v[r][c])continue;
            v[r][c] = true;

            if(r > 0 && board[r - 1][c] == 'O'){
                board[r - 1][c] = 'T';
                q.push({r - 1, c});
            }
            if(r < rows - 1 && board[r + 1][c] == 'O'){
                board[r + 1][c] = 'T';
                q.push({r + 1, c});
            }
            if(c > 0 && board[r][c - 1] == 'O'){
                board[r][c - 1] = 'T';
                q.push({r, c - 1});
            }
            if(c < cols - 1 && board[r][c + 1] == 'O'){
                board[r][c + 1] = 'T';
                q.push({r, c + 1});
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O')board[i][j] = 'X';
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'T')board[i][j] = 'O';
            }
        }
    }
};
