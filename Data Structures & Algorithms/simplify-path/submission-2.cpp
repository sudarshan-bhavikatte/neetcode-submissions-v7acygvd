class Solution {
public:
    string simplifyPath(string path) {
        path += "/";

        stack<string> s;
        string curr = "";
        for(char c : path){
            if(c == '/'){
                if(curr == ".."){
                    if(!s.empty())s.pop();
                } else {
                    if(curr != "" && curr != ".")s.push(curr);
                }
                curr = "";
            } else {
                curr += c;
            }
        }

        string res = "";

        while(!s.empty()){
            res = "/" + s.top() + res;
            s.pop();
        }

        return res == "" ? "/" : res;
    }
};