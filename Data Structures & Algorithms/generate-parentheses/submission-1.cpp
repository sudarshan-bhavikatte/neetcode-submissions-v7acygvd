class Solution {
public:

    void backtracking(vector<string>& res, string s, int open, int close , int n){

        if(s.size() == 2*n){
            res.push_back(s);
            return;
        }

        if(open < n){
            backtracking(res, s + "(", open + 1,close,n);    
        }
        if (close < open){
            backtracking(res, s + ")", open,close + 1,n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;

        backtracking(res, "", 0,0,n);
        return res;
    }
};
