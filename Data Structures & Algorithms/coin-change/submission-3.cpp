class Solution {
    int dfs(vector<int>& coins, int i, int amount){
        if(amount == 0) return 0;
        if(i == coins.size()){
            return INT_MAX;
        }

        int skip = dfs(coins, i + 1, amount);

        int include = INT_MAX;

        if(amount - coins[i] >= 0){
            int sub = dfs(coins, i, amount - coins[i]);
            if(sub != INT_MAX)include = 1 + sub;
        }

        return min(skip, include);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins, 0, amount);
        return res == INT_MAX ? -1 : res;
    }
};
