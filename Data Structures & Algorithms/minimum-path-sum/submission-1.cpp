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
    int minPathSum(vector<vector<int>>& grid) { return dfs(grid, 0, 0); }
};