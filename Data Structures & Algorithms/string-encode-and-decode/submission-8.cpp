class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string str : strs){
            res += (to_string(str.size()) + "#" + str);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        string str = "";
        int k = 0;
        while(i < s.size()){
            if(isdigit(s[i])){
                k = (k * 10) + (s[i] - '0');
                i++;
            }
            else if(s[i] == '#'){
                i++;
                while(k > 0){
                    str += s[i];
                    k--;
                    i++;
                }
                res.push_back(str);
                str = "";
            }
        }
        return res;
    }
};
