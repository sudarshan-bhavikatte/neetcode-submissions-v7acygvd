class Solution {
    int m;
    int n;
    vector<vector<int>> memo;

    int dfs(int i, int j){
        if(i >= m || j >= n)return 0;
        if(i == m - 1 && j == n - 1)return 1;
        if(memo[i][j] != -1) return memo[i][j];
        int right = dfs(i, j + 1);
        int down = dfs(i + 1, j);

        memo[i][j] = right + down;
        return memo[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;
        memo.assign(m, vector<int>(n, -1));

        dfs(0,0);
        return memo[0][0] == -1 ? 1 : memo[0][0];
    }
};
