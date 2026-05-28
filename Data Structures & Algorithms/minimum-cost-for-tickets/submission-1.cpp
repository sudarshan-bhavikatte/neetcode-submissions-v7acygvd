class Solution {
    unordered_map<int, int> memo;
    int dfs(vector<int>& days, vector<int>& costs, int i) {
        if(memo.find(i) != memo.end())return memo[i];
        if (i == days.size()) return 0;

        int one_day_pass = costs[0] + dfs(days, costs, i + 1);
        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) {
            j++;
        }
        int seven_day_pass = costs[1] + dfs(days, costs, j);

        j = i;
        while (j < days.size() && days[j] < days[i] + 30) {
            j++;
        }
        int thirty_day_pass = costs[2] + dfs(days, costs, j);

        memo[i] = min({one_day_pass, seven_day_pass, thirty_day_pass}); 
        return min({one_day_pass, seven_day_pass, thirty_day_pass});
    }

   public:
    int mincostTickets(vector<int>& days, vector<int>& costs) { 
        return dfs(days, costs, 0); 
    }
};