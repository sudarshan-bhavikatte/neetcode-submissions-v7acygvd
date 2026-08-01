class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size() - 1;
        int cols = board[0].size() - 1;

        unordered_map<int, unordered_map<char, int>> rows_hash;
        unordered_map<int, unordered_map<char, int>> cols_hash;
        unordered_map<int, unordered_map<char, int>> box_hash;

        for(int i = 0; i <= rows; i++){
            for(int j = 0; j <= cols; j++){
                if(board[i][j] == '.')continue;
                char val = board[i][j];
                int r = i;
                int c = j;
                int b = (i / 3) * 3 + (j / 3);

                if(rows_hash[r][val])return false;
                rows_hash[r][val]++;
                if(cols_hash[c][val])return false;
                cols_hash[c][val]++;
                if(box_hash[b][val])return false;
                box_hash[b][val]++;
            }
        }

        return true;
    }
};
