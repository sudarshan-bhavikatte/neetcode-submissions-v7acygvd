class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];

        for(int i = 1; i < strs.size(); i++){
            int j = 0;
            while(j <= res.length() && res[j] == strs[i][j]){
                j++;
            }
            res = strs[i].substr(0,j);
        }

        return res;
            
    }
};