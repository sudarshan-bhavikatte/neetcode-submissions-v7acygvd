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

        int idx = 0;

        while(idx < s.size()){
            int size = 0;
            while(s[idx] != '#'){
                size = size * 10 + (s[idx++] - '0');
            }
            if(size == 0)res.push_back("");
            else res.push_back(s.substr(idx + 1, size));
            idx = idx + 1 + size;
        }

        return res;
    }
};
