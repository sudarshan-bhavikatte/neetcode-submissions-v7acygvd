class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        if(m == 1 && n == 1) return 1;

        for(int i = m - 1; i >= 0; i--){
            if(obstacleGrid[i][n - 1] == 1)break;
            dp[i][n - 1] = 1;
        }

        for(int j = n - 1; j >= 0; j--){
            if(obstacleGrid[m - 1][j] == 1)break;
            dp[m - 1][j] = 1;
        }

        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                int right = obstacleGrid[i][j + 1] == 1 ? 0 : dp[i][j+1]; 
                int down = obstacleGrid[i + 1][j] == 1 ? 0 : dp[i + 1][j];

                dp[i][j] = right + down; 
            }
        }

        return dp[0][0];
    }
};