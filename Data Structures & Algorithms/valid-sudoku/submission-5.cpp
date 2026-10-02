class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<int, int>> row_hash;
        unordered_map<int, unordered_map<int, int>> col_hash;
        unordered_map<int, unordered_map<int, int>> box_hash;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                char c = board[i][j];
                if(c == '.')continue;

                int num = c - '0';
                if(row_hash[i].count(num))return false;
                if(col_hash[j].count(num))return false;
                if(box_hash[(i / 3) * 3 + (j / 3)].count(num))return false;

                row_hash[i][num]++;
                col_hash[j][num]++;
                box_hash[(i / 3) * 3 + (j / 3)][num]++;
            }
        }

        return true;
    }
};
