class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();

        // dp[i][j][k] = max subset from strs[i..end] with j zeros, k ones left
        vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // base case: dp[sz][*][*] = 0 (i == strs.size()) — already initialized

        for (int i = sz - 1; i >= 0; i--) {
            int zeros = 0, ones = 0;
            for (char c : strs[i]) {
                if (c == '0') zeros++;
                else ones++;
            }

            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    // skip strs[i]
                    dp[i][j][k] = dp[i + 1][j][k];

                    // take strs[i] if it fits
                    if (j >= zeros && k >= ones)
                        dp[i][j][k] = max(dp[i][j][k], 1 + dp[i + 1][j - zeros][k - ones]);
                }
            }
        }

        return dp[0][m][n];  // original call was dfs(0, m, n)
    }
};