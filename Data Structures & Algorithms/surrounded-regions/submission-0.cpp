class Solution {

private:
    int ROWS;
    int COLS;

    void dfs(int r, int c, vector<vector<char>>& board){

        if(
            r < 0 ||
            c < 0 ||
            r >= ROWS ||
            c >= COLS ||
            board[r][c] != 'O'
        ) {
            return;
        }

        board[r][c] = 'T';

        dfs(r + 1, c, board);
        dfs(r - 1, c, board);
        dfs(r, c + 1, board);
        dfs(r, c - 1, board);
    
    }
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        for(int i =0; i<ROWS; i++){
                if(board[i][0] == 'O')dfs(i, 0, board);
                if(board[i][COLS - 1] == 'O')dfs(i, COLS - 1, board);
        }

        for(int j=0; j<COLS; j++){
            if(board[0][j] == 'O')dfs(0, j, board);    
            if(board[ROWS - 1][j] == 'O')dfs(ROWS - 1, j, board);
        }

        for(int i =0; i< ROWS; i++){
            for(int j=0; j<COLS; j++){
                
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
