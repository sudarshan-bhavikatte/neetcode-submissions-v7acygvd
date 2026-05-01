class Solution {
    vector<vector<int>> grid;
    int m;
    int n;
    vector<vector<int>> memo;
    int dfs(int i, int j){
        if( i >= m || j >= n){
            return 0;
        }
        if(grid[i][j] == 1) return 0;
        if(i == m -1 && j == n - 1)return 1;

        if(memo[i][j] != -1) return memo[i][j];

        memo[i][j] = dfs(i + 1, j) + dfs(i, j + 1);

        return memo[i][j];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        grid = obstacleGrid;         
        if(grid[0][0] == 1) return 0;
        if(m == 1 && n == 1) return 1;


        memo.assign(m, vector<int>(n, -1));
        dfs(0,0);
        return memo[0][0];
    }
};