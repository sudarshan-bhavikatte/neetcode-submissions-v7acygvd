class Solution {
    vector<string> res;

    void helper(string str, int n, int open, int closed){
        if(str.size() == n * 2){
            res.push_back(str);
            return;
        }
        if(str.size() > n * 2) return;

        if(open < n){
            str += '(';
            helper(str, n, open + 1, closed);
            str.pop_back();
        }
        if(closed < open){
            str += ')';
            helper(str, n, open, closed + 1);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string str = "";

        helper(str, n, 0, 0);

        return res;
    }
};
