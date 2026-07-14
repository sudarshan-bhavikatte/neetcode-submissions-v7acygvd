class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<int, int>> rows;
        unordered_map<int, unordered_map<int, int>> cols;
        unordered_map<int, unordered_map<int, int>> boxs;

        int r = board.size();
        int c = board[0].size();

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == '.') continue;
                if(rows[i].find(board[i][j] - '0') != rows[i].end() ||
                    cols[j].find(board[i][j] - '0') != cols[j].end() ||
                    boxs[(i / 3) * 3 + (j / 3)].find(board[i][j] - '0') != boxs[(i / 3) * 3 + (j / 3)].end()
                ) return false;
                rows[i][board[i][j] - '0'] = 1;
                cols[j][board[i][j] - '0'] = 1;
                boxs[(i / 3) * 3 + (j / 3) ][board[i][j] - '0'] = 1;
            }
        }
        return true;
    }
};
