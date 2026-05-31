class Solution {
    int dfs(string word1, string word2, int i, int j){
        if(i == word1.size())return word2.size() - j;
        if(j == word2.size())return word1.size() - i;

        int res = INT_MAX;

        if(word1[i] == word2[j]){
            res = dfs(word1, word2, i + 1, j + 1);
        }
        else {
            res = 1 + min({dfs(word1, word2, i + 1, j), 
                dfs(word1, word2, i, j + 1),
                dfs(word1, word2, i + 1, j + 1)
            });
        }

        return res;
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        for(int i = m; i >= 0; i--)dp[i][n] = m - i;
        for(int j = n; j >= 0; j--)dp[m][j] = n - j;

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(word1[i] == word2[j])dp[i][j] = dp[i + 1][j + 1];
                else {
                    dp[i][j] = 1 + min({
                        dp[i + 1][j],
                        dp[i][j + 1],
                        dp[i + 1][j + 1]
                    });
                }
            }
        }

        return dp[0][0];
    }
};
