class Solution {
public:

    string helper(int& i, string& s){
        string res = "";
        int k = 0;
        while(i < s.size()){
            if(isdigit(s[i])){
                k = k * 10 + (s[i] - '0');
                i++;
            } else if(s[i] == '['){
                i++;
                string subStr = helper(i, s);
                while(k){
                    res += subStr;
                    k--;
                }
            } else if(s[i] == ']'){
                i++;
                return res;
            } else {
                res += s[i];
                i++;
            }
        }

        return res;
    }
    string decodeString(string s) {
        string res = "";
        int k = 0;
        int i = 0;
        while(i < s.size()){
            if(isdigit(s[i])){
                k = k * 10 + (s[i] - '0');
                i++;
            } else if(s[i] == '['){
                i++;
                string subStr = helper(i, s);
                while(k){
                    res += subStr;
                    k--;
                }
            } else if(s[i] == ']'){
                i++;
                return res;
            }
            else {
                res += s[i];
                i++;
            }
        }

        return res;
    }
};