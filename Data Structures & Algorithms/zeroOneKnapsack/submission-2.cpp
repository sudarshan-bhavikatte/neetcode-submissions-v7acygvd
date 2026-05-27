class Solution {
    vector<vector<int>> memo;

    int dfs(vector<int>& profit, vector<int>& weight, int i, int capacity){
        if(i == profit.size()){
            return 0;
        }
        if(memo[i][capacity] != -1)return memo[i][capacity];

        int maxProfit = dfs(profit, weight, i + 1, capacity);

        int newCap = capacity - weight[i];

        if(newCap >= 0){
            int include = profit[i] + dfs(profit, weight, i + 1, newCap);
            maxProfit = max(maxProfit, include); 
        }
        memo[i][capacity] = maxProfit;
        return maxProfit;
    }
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        memo.assign(weight.size(), vector<int>(capacity + 1, -1));
        return dfs(profit, weight, 0, capacity);
    }
};
