class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 !=0)return false;
        vector<char> stack;

        for(char c : s){
            if ( c == '(' || c == '{' || c == '['){
                stack.push_back(c);
            }
            else {
                if(stack.empty())return false;
                char last = stack.back();
                if(c == '}'){
                    if(last != '{')return false;
                }
                else if(c == ')'){
                    if(last != '(')return false;
                }
                else if(c == ']'){
                    if(last != '[')return false;
                }
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};
