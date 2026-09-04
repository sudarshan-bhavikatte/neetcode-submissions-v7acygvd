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
        return dfs(0,0, m, n);
    }
};
