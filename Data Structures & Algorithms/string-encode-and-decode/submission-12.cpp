class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s : strs){
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        int k = 0;
        vector<string> res;
        while(i < s.size()){
            if(isdigit(s[i])){
                k = k * 10 + (s[i] - '0');
                i++;
            }
            else if (s[i] == '#'){
                string str = "";
                i++;
                while(k > 0){
                    str += s[i];
                    i++;
                    k--;
                }
                res.push_back(str);
            }
        }
        return res;
    }
};
