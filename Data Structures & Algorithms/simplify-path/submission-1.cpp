class Solution {
public:
    string simplifyPath(string path) {
        string cur = "";
        stack<string> s;

        for(char c : path + '/'){
            if(c == '/'){
                if(cur == ".."){
                    if(!s.empty())s.pop();
                }
                else if ( !cur.empty() && cur != ".") s.push(cur);
                cur.clear();
            }
            else {
                cur += c;
            }
        }
        string res = "/";
        stack<string> temp;
        while(!s.empty()){
            temp.push(s.top()); s.pop();
        }

        while(!temp.empty()){
            res += temp.top() + '/';
            temp.pop();
        }
        if (res == "/") return res;
        return res.substr(0, res.size() - 1);
    }
};