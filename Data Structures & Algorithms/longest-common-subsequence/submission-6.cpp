class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();
        vector<vector<int>> dp(s1, vector<int>(s2, 0));

        if (text1[s1 - 1] == text2[s2 - 1]) dp[s1 - 1][s2 - 1] = 1;

        // last column
        for (int i = s1 - 2; i >= 0; i--) {
            dp[i][s2 - 1] = (text1[i] == text2[s2 - 1]) ? 1 : dp[i + 1][s2 - 1];
        }

        // last row
        for (int j = s2 - 2; j >= 0; j--) {
            dp[s1 - 1][j] = (text1[s1 - 1] == text2[j]) ? 1 : dp[s1 - 1][j + 1];
        }

        for (int i = s1 - 2; i >= 0; i--) {
            for (int j = s2 - 2; j >= 0; j--) {
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};
