class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];

        for(int i = 1; i < strs.size(); i++){
            int idx = 0;

            while(idx <= strs[i].size() - 1 && strs[i][idx] == res[idx]) idx++;

            res = strs[i].substr(0, idx);
        }

        return res;
    }
};