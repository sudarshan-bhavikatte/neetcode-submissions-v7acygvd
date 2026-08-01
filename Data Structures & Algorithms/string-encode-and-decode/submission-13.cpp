class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for(string str : strs){
            int size = str.size();
            res += to_string(size);
            res += "#";
            res += str;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = s.size();
        int i = 0;
        int k = 0;
        while(i < n){
            if(s[i] >= '0' && s[i] <= '9'){
                k = (k * 10) + (s[i] - '0');
                i++;
            }
            else if(s[i] == '#'){
                string str = "";
                i++;
                while(k > 0){
                    str += s[i];
                    i++; k--;
                }

                res.push_back(str);
            }
        }

        return res;
    }
};
