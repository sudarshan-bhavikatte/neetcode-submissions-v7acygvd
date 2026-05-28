class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(string text1, string text2, int i, int j){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(j) != memo[i].end()){
                return memo[i][j];
            }
        }
        if(i == text1.size() || j == text2.size()){
            return 0;
        }
        int res = 0;
        if(text1[i] == text2[j]){
            res = 1 + dfs(text1, text2, i + 1, j + 1);
        }
        else{
            res = dfs(text1, text2, i + 1, j);
            res = max(res, dfs(text1, text2, i, j + 1));
        }
        memo[i][j] = res;
        return res;
    }
public:
    // int longestCommonSubsequence(string text1, string text2) {
    //     return dfs(text1, text2, 0, 0);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};
