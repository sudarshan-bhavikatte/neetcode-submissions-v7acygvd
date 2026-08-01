class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];

        for(int i = 1; i < strs.size(); i++){
            string s = strs[i];
            if(s.size() < res.size()) res = res.substr(0, res.size());
            for(int idx = 0; idx < res.size(); idx++){
                if(res[idx] != s[idx]){
                    res = s.substr(0, idx);
                }
            }
        }

        return res;
    }
};