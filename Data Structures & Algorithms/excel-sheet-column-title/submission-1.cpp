class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        
        while(columnNumber > 0){
            columnNumber--;
            int q = columnNumber / 26;
            int r = columnNumber % 26;

            s += (r + 'A');
            columnNumber = q;
        }

        reverse(s.begin(), s.end());

        return s;
    }
};