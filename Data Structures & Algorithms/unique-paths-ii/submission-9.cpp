class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(int r, int c, int m, int n, vector<vector<int>>& grid){
        if(memo.count(r) && memo[r].count(c)) return memo[r][c];
        if(r == m || c == n || grid[r][c] == 1) return 0;
        if(r == m - 1 && c == n - 1) return 1;

        memo[r][c] = dfs(r + 1, c, m, n, grid) + dfs(r, c + 1, m, n, grid); 
        return memo[r][c];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m - 1][n - 1] == 1)return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i + 1 < m && grid[i + 1][j] == 0)dp[i][j] += dp[i + 1][j];
                if(j + 1 < n && grid[i][j + 1] == 0)dp[i][j] += dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};