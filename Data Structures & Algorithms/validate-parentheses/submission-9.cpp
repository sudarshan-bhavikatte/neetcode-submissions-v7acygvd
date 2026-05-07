class Solution {
public:
    bool isValid(string s) {

        if(s.size() == 1)return false;
        vector<char> stack;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' ||
                s[i] == '{' ||
                s[i] == '['
            ) {
                stack.push_back(s[i]);
            }
            else if(
                s[i] == ')'
            ) {
                if(stack.empty())return false;
                if (stack.back() == '(')stack.pop_back();
                else return false;
            }
            else if(
                s[i] == '}'
            ) {
                if(stack.empty())return false;
                if (stack.back() == '{')stack.pop_back();
                else return false;
            }else if(
                s[i] == ']'
            ) {
                if(stack.empty())return false;
                if (stack.back() == '[')stack.pop_back();
                else return false;
            }
        }

        return stack.empty();
    }
};
