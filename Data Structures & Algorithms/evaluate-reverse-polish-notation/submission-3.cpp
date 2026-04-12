class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> stack;

        for(string token : tokens){

            if (token == "+" || token == "-" || token == "*" || token == "/"){
                if(stack.size() <2)return -1;

                int second = stoi(stack.back());
                stack.pop_back();

                int first = stoi(stack.back());
                stack.pop_back();
                
                if (token == "+"){
                    stack.push_back(to_string(first + second));
                }
                else if (token == "-"){
                    stack.push_back(to_string(first - second));
                }
                else if (token == "*"){
                    stack.push_back(to_string(first * second));
                }
                else if (token == "/"){
                    stack.push_back(to_string(first / second));
                }
            }
            else {
                stack.push_back(token);
            }
        }
        int res = stoi(stack.back());
        return res;
    }
};
