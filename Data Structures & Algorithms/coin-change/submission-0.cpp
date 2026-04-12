class Solution {

private:
    int dfs(int i, int sum, vector<int>& subset, vector<int>& coins, int amount){
        if(i == coins.size())return INT_MAX;
        if(sum == amount){
            return subset.size();
        }
        if (sum > amount)return INT_MAX;

        subset.push_back(coins[i]);
        int res1 = dfs(i, sum + coins[i], subset, coins, amount);
        subset.pop_back();
        int res2 = dfs(i + 1, sum, subset, coins, amount);

        return min(res1, res2);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>subset;
        int res = dfs(0, 0, subset, coins, amount);

        return res == INT_MAX ? -1 : res;  
    }
};
