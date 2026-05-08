class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rs = 0;
        int re = matrix.size() - 1;

        int cs = 0;
        int ce = matrix[0].size() - 1;

        while(rs <= re){
            int rm = (rs + re) / 2;
            if(matrix[rm][cs] <= target && matrix[rm][ce] >= target){
                while(cs <= ce){
                    int cm = (cs + ce) / 2;
                    if(matrix[rm][cm] == target) return true;
                    else if(matrix[rm][cm] > target) ce = cm - 1;
                    else cs = cm + 1;
                }
            }
            else if(matrix[rm][cs] < target && matrix[rm][ce] < target){
                rs = rm + 1;
            }
            else re = rm - 1;
        }

        return false;
    }
};
