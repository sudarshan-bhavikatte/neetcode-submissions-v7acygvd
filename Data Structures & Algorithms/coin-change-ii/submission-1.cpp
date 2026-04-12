class Solution {
private:
    vector<vector<int>> memo;

    int dfs(int i, int amount, vector<int>& coins) {

        if (amount < 0) return 0;
        if (amount == 0) return 1;
        if (i == coins.size()) return 0;

        if (memo[i][amount] != -1)
            return memo[i][amount];

        int include = dfs(i, amount - coins[i], coins);
        int dont = dfs(i + 1, amount, coins);

        return memo[i][amount] = include + dont;
    }

public:
    int change(int amount, vector<int>& coins) {
        memo.assign(coins.size(), vector<int>(amount + 1, -1));
        return dfs(0, amount, coins);
    }
};
