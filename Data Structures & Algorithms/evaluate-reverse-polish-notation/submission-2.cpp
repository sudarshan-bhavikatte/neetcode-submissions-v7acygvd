class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> stack;

        for(string token : tokens){
            cout << token << endl;
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int second = stoi(stack.back());
                stack.pop_back();
                int first = stoi(stack.back());
                // cout << first << " " << token << " " << second << endl;
                stack.pop_back();
                    if(token == "+"){
                        stack.push_back(to_string(first + second));
                    }
                    if(token == "-"){
                        stack.push_back(to_string(first - second));
                    }
                    if(token == "*"){
                        stack.push_back(to_string(first * second)); 
                    }
                    if(token == "/"){
                        stack.push_back(to_string(first / second));
                    }                  
                }
            else {
                stack.push_back(token);
            }
        }
        return stoi(stack.back());
        }
};
