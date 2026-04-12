class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};


    vector<string> letterCombinations(string digits) {
        if(digits.empty())return res;
        backtrack(0, "", digits);
        return res; 
    }

    void backtrack(int index, string combi, string digits){
        if(combi.length() == digits.length()){
            res.push_back(combi);
            return;
        }

        for(char c : digitToChar[digits[index] - '0']){
            backtrack(index + 1, combi + c, digits);
        }
        return;
    }
};
