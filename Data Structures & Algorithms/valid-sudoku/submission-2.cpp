class Solution {
    vector<vector<bool>> r, c, b;

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        r.assign(9, vector<bool>(9, false));
        c.assign(9, vector<bool>(9, false));
        b.assign(9, vector<bool>(9, false));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '1'; // 0 to 8

                int box = (i / 3) * 3 + (j / 3);

                if(r[i][num] || c[j][num] || b[box][num])
                    return false;

                r[i][num] = c[j][num] = b[box][num] = true;
            }
        }
        return true;
    }
};