class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(string s, int i, int j) {
        if (memo.find(i) != memo.end()) {
            if (memo[i].find(j) != memo[i].end()) {
                return memo[i][j];
            }
        }
        if (i > j) {
            return (j - i + 1);
        }
        int res = 0;
        if (s[i] == s[j]) {
            res = 2 + dfs(s, i + 1, j - 1);
        } else {
            res = dfs(s, i + 1, j);
            res = max(res, dfs(s, i, j - 1));
        }
        memo[i][j] = res;
        return res;
    }

   public:
    // int longestPalindromeSubseq(string s) {
    //     return dfs(s, 0, s.size() - 1);
    // }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: single characters are palindromes of length 1
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        // Fill by increasing substring length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;  // window end

                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};