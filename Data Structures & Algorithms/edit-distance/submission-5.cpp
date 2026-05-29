class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(string word1, string word2, int i, int j){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(j) != memo[i].end()){
                return memo[i][j];
            }
        }
        if(i == word1.size())return word2.size() - j;
        if(j == word2.size())return word1.size() - i;

        int res = INT_MAX;
        if(word1[i] == word2[j]){
            res = dfs(word1, word2, i + 1, j + 1);
        }
        else {
            int replace = 1 + dfs(word1, word2, i + 1, j + 1);
            int ins = 1 + dfs(word1, word2, i, j + 1);
            int del = 1 + dfs(word1, word2, i + 1, j);

            res = min({replace, del, ins}); 
        }

        memo[i][j] = res;
        return res;
    }
public:
    // int minDistance(string word1, string word2) {
    //     return dfs(word1, word2, 0, 0);
    // }

    int minDistance(string word1, string word2) {
        int m = word1.size(); int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        for(int j = 0; j <= n; j++){
            dp[m][j] = n - j; 
        }
        for(int i = 0; i <= m; i++){
            dp[i][n] = m - i; 
        }

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(word1[i] == word2[j]) dp[i][j] = dp[i+1][j+1];
                else {
                    dp[i][j] = min({
                        1 + dp[i + 1][j + 1],
                        1 + dp[i][j + 1],
                        1 + dp[i + 1][j]
                    });
                }
            }
        }

        return dp[0][0];
    }
};
