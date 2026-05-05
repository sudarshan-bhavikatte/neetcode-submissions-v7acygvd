class NumMatrix {
    vector<vector<int>> pre;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        pre.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(j == 0)pre[i][j] = matrix[i][j];
                else {
                    pre[i][j] = pre[i][j - 1] + matrix[i][j];
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                cout << pre[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        int flag = col1 > 0 ? 1 : 0; 
        for(int i = row1; i <= row2; i++){
            if(col1 == 0) res += pre[i][col2];
            else res += pre[i][col2] - pre[i][col1 - flag];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */