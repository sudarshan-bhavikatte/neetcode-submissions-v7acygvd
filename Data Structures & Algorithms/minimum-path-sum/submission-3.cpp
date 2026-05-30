class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(memo.find(i) != memo.end()){
            if(memo[i].find(j) != memo[i].end()){
                return memo[i][j];
            }
        }
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        int cost = INT_MAX;
        if (i + 1 <= grid.size() - 1) {
            cost = grid[i][j] + dfs(grid, i + 1, j);
        }
        if (j + 1 <= grid[0].size() - 1) {
            cost = min(grid[i][j] + dfs(grid, i, j + 1), cost);
        }

        memo[i][j] = cost;
        return cost;
    }

   public:
    // int minPathSum(vector<vector<int>>& grid) { 
    //     return dfs(grid, 0, 0); 
    // }
    int minPathSum(vector<vector<int>>& grid) { 
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        for(int i = m - 2; i >= 0; i--){
            dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];
        }
        for(int j = n - 2; j >= 0; j--){
            dp[m - 1][j] = dp[m - 1][j + 1] + grid[m - 1][j];
        }

        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
            }
        }

        return dp[0][0];
    }
};