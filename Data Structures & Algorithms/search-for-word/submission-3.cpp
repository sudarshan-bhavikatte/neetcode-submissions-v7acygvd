class Solution {
    vector<vector<bool>> v;
    string word;
    vector<vector<char>> board;
    int rows;
    int cols;

    bool helper(int i, int j, int idx) {
        
        if (idx == word.size()) return true;

        if ( i < 0 || j < 0 || i >= rows || j >= cols || v[i][j]) return false;

        if (board[i][j] != word[idx])
            return false;
        else {
            v[i][j] = true;
            cout << i << " "<< j << " " << board[i][j] << endl;
            bool left = helper(i, j - 1, idx + 1);
            bool right = helper(i, j + 1, idx + 1);
            bool up = helper(i - 1, j, idx + 1);
            bool down = helper(i + 1, j, idx + 1);
            
            v[i][j] = false;
            return left || right || up || down;
        }
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        this->rows = board.size();
        this->cols = board[0].size();

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    v.assign(board.size(), vector<bool>(board[0].size(), false));
                    if (helper(i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
