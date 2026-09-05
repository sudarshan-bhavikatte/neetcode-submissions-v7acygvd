class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(int i, int sum, vector<int>& stones, int total){
        if(memo.count(i) && memo[i].count(sum))return memo[i][sum];
        if(sum >= ((total + 1) / 2) || i >= stones.size()){
            return abs(sum - (total - sum));
        }

        memo[i][sum] = min(
            dfs(i + 1, sum + stones[i], stones, total),
            dfs(i + 1, sum, stones, total)
        );
        return memo[i][sum];
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);

        return dfs(0, 0, stones, total);
    }
};