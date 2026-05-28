class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(vector<int>& stones, int i, int sum, int need, int total){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(sum) != memo[i].end()){
                return memo[i][sum];
            }
        }
        if(i == stones.size()){
            return abs(sum - (total - sum));
        }

        int skip = dfs(stones, i + 1, sum, need, total);
        int include = dfs(stones, i + 1, sum + stones[i], need, total);

        memo[i][sum] = min(skip, include);
        return min(skip, include);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        int need = (total + 1) / 2;

        return dfs(stones, 0, 0, need, total);
    }
};