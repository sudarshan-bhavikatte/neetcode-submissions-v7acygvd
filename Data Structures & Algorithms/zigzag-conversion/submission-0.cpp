class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string res;
        int offset = 2 * (numRows - 1);

        for (int row = 0; row < numRows; row++) {
            for (int i = row; i < s.size(); i += offset) {
                res += s[i];

                int diag = i + offset - 2 * row;

                if (row != 0 &&
                    row != numRows - 1 &&
                    diag < s.size()) {
                    res += s[diag];
                }
            }
        }

        return res;
    }
};