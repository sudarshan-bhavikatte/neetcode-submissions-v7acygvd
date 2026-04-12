class Solution {
public:
    int ROWS;
    int COLS;

    set<pair<int, int>> PATH;
    
    bool exist(vector<vector<char>>& board, string word) {

        ROWS = board.size();
        COLS = board[0].size();
        
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++){
                if(dfs(board, word, i, j, 0))return true;
            }
        }

        return false; 
    }

    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index){

        if(index == word.length())return true;

        if(row < 0 ||
            col < 0 ||
            row >= ROWS ||
            col >= COLS ||
            board[row][col] != word[index] ||
            PATH.count({row, col}) == 1
            ){
                return false;
        }
        PATH.insert({row,col});

        bool res = dfs(board, word, row + 1, col,index+1) ||
            dfs(board, word, row - 1, col,index+1) ||
            dfs(board, word, row, col + 1,index+1) ||
            dfs(board, word, row, col - 1,index+1);

        PATH.erase({row,col});
        return res;
    }
};
