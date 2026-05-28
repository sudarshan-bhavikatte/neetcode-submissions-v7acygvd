class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(vector<int>& coins, int i, int amount){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(amount) != memo[i].end()){
                return memo[i][amount];
            }
        }
        if(amount == 0)return 1;
        if(i == coins.size())return 0;

        int skip = dfs(coins, i + 1, amount);
        int include = 0;

        if(amount - coins[i] >= 0){
            include = dfs(coins, i, amount - coins[i]);
        }

        memo[i][amount] = skip + include;
        return skip + include;
    }
public:
    int change(int amount, vector<int>& coins) {
        return dfs(coins, 0, amount);
    }
};
