class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];

        for(int i = 1; i < strs.size(); i++){
            int idx = 0;

            while(idx < strs[i].size() && idx < res.size() && res[idx] == strs[i][idx])idx++;

            res = res.substr(0, idx);
        }

        return res;
    }
};