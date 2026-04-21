class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_s = 0;
        int row_e = matrix.size() - 1;

        int COLS = matrix[0].size();

        while (row_s <= row_e) {
            int row_m = (row_s + row_e) / 2;

            if (target > matrix[row_m][COLS - 1]) {
                row_s = row_m + 1;
            } else if (target < matrix[row_m][0]) {
                row_e = row_m - 1;
            } else {
                // correct row
                break;
            }
        }
        if (!(row_s <= row_e)) return false;

        int row = (row_s + row_e) / 2;
        int col_s = 0;
        int col_e = matrix[0].size() - 1;

        while (col_s <= col_e) {
            int col_m = (col_s + col_e) / 2;
            if (matrix[row][col_m] == target)
                return true;
            else if (matrix[row][col_m] < target) {
                col_s = col_m + 1;
            } else {
                col_e = col_m - 1;
            }
        }

        return false;
    }
};
