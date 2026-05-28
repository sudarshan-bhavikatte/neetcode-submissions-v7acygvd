class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(vector<int>& profit, vector<int>& weight,int i, int capacity){
        if(memo.find(i) != memo.end() 
            && memo[i].find(capacity) != memo[i].end())return memo[i][capacity];

        if(i == profit.size())return 0;

        int skip = dfs(profit, weight, i + 1, capacity);

        int newCap = capacity - weight[i];

        int include = INT_MIN;
        if(newCap >= 0){
            include = profit[i] + dfs(profit, weight, i, newCap);
        }
        memo[i][capacity] = max(skip, include);
        return max(skip, include);
    }
public:
    // int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
    //     return dfs(profit, weight, 0, capacity);        
    // }

    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int n = profit.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= capacity; j++){
                int skip = dp[i + 1][j];
                int include = INT_MIN;
                if(j - weight[i] >= 0){
                    include = profit[i] + dp[i][j - weight[i]]; 
                }

                dp[i][j] = max(skip, include);
            }
        }

        return dp[0][capacity];        
    }
};
