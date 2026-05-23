class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<bool> row_zeros(rows, false);
        vector<bool> col_zeros(cols, false);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    row_zeros[i] = true;
                    col_zeros[j] = true;
                }
            }
        }

        for(int i = 0; i < rows; i++){
            if(row_zeros[i]){
                for(int j = 0; j < cols; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0; j < cols; j++){
            if(col_zeros[j]){
                for(int i = 0; i < rows; i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
