class NumMatrix {
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> col_sums;
        col_sums.resize(rows, vector<int>(cols, 0));
        vector<vector<int>>row_sums;
        row_sums.resize(rows, vector<int>(cols, 0));

        prefix.resize(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i++){
            int total = 0;
            for(int j = 0; j < cols; j++){
                total += matrix[i][j];
                col_sums[i][j] = total;
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i == 0){
                    row_sums[i][j] = matrix[i][j]; 
                }
                else{
                    row_sums[i][j] = matrix[i][j] + row_sums[i - 1][j];
                }
            }
        }

        for(int i = 0; i < cols; i++){
            prefix[0][i] = col_sums[0][i];
        }

        for(int i = 0; i < rows; i++){
            prefix[i][0] = row_sums[i][0];
        }

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                prefix[i][j] = matrix[i][j] + prefix[i - 1][j - 1] + row_sums[i - 1][j] + col_sums[i][j - 1];
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cout << prefix[i][j] << " ";
            }
            cout << "\n";
        }
        // cout << "\n";
        // for(int i = 0; i < rows; i++){
        //     for(int j = 0; j < cols; j++){
        //         cout << row_sums[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int res = prefix[row2][col2];
        
        if(row1 != 0) res -= prefix[row1 - 1][col2];
        if(col1 != 0) res -= prefix[row2][col1 - 1];

        if(row1 != 0 && col1 != 0) res += prefix[row1 - 1][col1 - 1];

        return res; 

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */