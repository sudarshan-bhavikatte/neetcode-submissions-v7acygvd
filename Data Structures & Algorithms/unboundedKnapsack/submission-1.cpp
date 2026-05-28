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
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        return dfs(profit, weight, 0, capacity);        
    }
};
