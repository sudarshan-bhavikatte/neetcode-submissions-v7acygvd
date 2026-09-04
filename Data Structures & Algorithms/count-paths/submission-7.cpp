class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(int r, int c, int m, int n){
        if(r == m - 1 && c == n - 1) return 1;
        if(memo.count(r) && memo[r].count(c))return memo[r][c];

        if(r == m || c == n)return 0;

        memo[r][c] = dfs(r + 1, c, m, n) + dfs(r, c + 1, m, n); 
        return memo[r][c];
    }
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[m - 1][n - 1] = 1;

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i + 1 < m) dp[i][j] += dp[i + 1][j];
                if(j + 1 < n) dp[i][j] += dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};
