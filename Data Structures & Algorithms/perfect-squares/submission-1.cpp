class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(int n, int i){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(n) != memo[i].end()){
                return memo[i][n];
            }
        }
        if(n == 0)return 0;
        if(i * i > n)return INT_MAX;

        int skip = dfs(n, i + 1);
        int include = INT_MAX;
        if(n - (i * i) >= 0){
            int sub = dfs(n - (i * i), i);
            if(sub != INT_MAX)include = 1 + sub;
        }
        memo[i][n] = min(skip, include);
        return min(skip, include);
    }
public:
    int numSquares(int n) {
       return dfs(n , 1); 
    }
};