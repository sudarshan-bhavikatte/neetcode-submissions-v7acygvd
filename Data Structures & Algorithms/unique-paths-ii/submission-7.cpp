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
        return dfs(0, 0, m, n, grid);
    }
};