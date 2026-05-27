class Solution {
    unordered_map<int, unordered_map<string, int>> memo;
    int dfs(vector<string>& strs, int i, int m, int n) {
        if(i == strs.size()){
            return 0;
        }
        
        vector<int> v(2, 0);
        for(char c : strs[i]){
            v[c - '0']++;
        }
        int newM = m - v[0];
        int newN = n - v[1];

        string key = to_string(m - v[0]) + "#" + to_string(n - v[1]);

        if(memo.find(i) != memo.end()){
            if(memo[i].find(key) != memo[i].end()){
                return memo[i][key];
            }
        }

        int res = dfs(strs, i + 1, m, n);

        if(newM >= 0 && newN >= 0){
            int include = 1 + dfs(strs, i + 1, newM, newN);
            res = max(res, include);
        }
        memo[i][key] = res;
        return res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<string> subset;
        return dfs(strs, 0, m, n);
    }
};