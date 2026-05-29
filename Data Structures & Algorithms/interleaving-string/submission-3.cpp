class Solution {
    unordered_map<int, unordered_map<int, bool>> memo;
    bool dfs(string s1, string s2, string s3, int i, int j){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(j) != memo[i].end()){
                return memo[i][j];
            }
        }
        if(i == s1.size() && j == s2.size()){
            return true;
        }
        if(i == s1.size()){
            if(s2[j] == s3[i + j]){
                return dfs(s1, s2, s3, i, j + 1);
            }
            else {
                return false;
            }
        }
        if(j == s2.size()){
            if(s1[i] == s3[i + j]){
                return dfs(s1, s2, s3, i + 1, j);
            }
            else {
                return false;
            }
        }
        bool res = false;
        if(s1[i] == s3[i + j] && s2[j] == s3[i + j]){
            res = dfs(s1, s2, s3, i + 1, j) || dfs(s1, s2, s3, i, j + 1);
        }
        else if(s1[i] == s3[i + j]){
            res = dfs(s1, s2, s3, i + 1, j);
        }
        else if(s2[j] == s3[i + j]){
            res = dfs(s1, s2, s3, i, j + 1);
        }
        else {
            return false;
        }
        memo[i][j] = res;
        return res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())return false;

        return dfs(s1, s2, s3, 0, 0);
    }
};
