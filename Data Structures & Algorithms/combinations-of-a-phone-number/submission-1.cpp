class Solution {
    vector<string> chars = {
        "",
        "",
        "abc", 
        "def", 
        "ghi", 
        "jkl", 
        "mno", 
        "pqrs",
        "tuv",
        "wxyz"
        };
    
    vector<string> res;
    string digits;

    void helper(string substr, int idx){
        if(idx == digits.size()){
            res.push_back(substr);
            return;
        }
        int charsIdx = digits[idx] - '0';
        for(int i = 0; i < chars[charsIdx].size(); i++){
            substr += chars[charsIdx][i];
            helper(substr, idx + 1);
            substr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;

        if(digits == "")return {};
        
        string substr = "";
        helper(substr, 0);
        
        return res;
    }
};
