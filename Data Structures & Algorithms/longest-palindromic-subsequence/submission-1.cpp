class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(string s, int i, int j){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(j) != memo[i].end()){
                return memo[i][j];
            }
        }
        if(i > j){
            return (j - i + 1);
        }
        int res = 0;
        if(s[i] == s[j]){
            res = 2 + dfs(s, i + 1, j - 1);
        }
        else{
            res = dfs(s, i + 1, j);
            res = max(res, dfs(s, i, j - 1));
        }
        memo[i][j] = res;
        return res;
    }
    int longestPalindromeSubseq(string s) {
        int res = dfs(s, 0, s.size() - 1);

        return res;
    }
};