class Solution {
private:
    unordered_map<int, int>hash;
    int dfs(int i, string& s){
        if(hash.find(i) != hash.end())return hash[i];

        if(i == s.size())return 1;
        if(s[i] == '0')return 0;

        int res = dfs(i + 1, s);
        if(
            i < s.size() - 1 &&
            (s[i] == '1') ||
            (s[i] == '2' && s[i + 1] < '7')
        ){
            res += dfs(i + 2, s);
        }
        hash[i] = res;
        return res;
    }
public:
    int numDecodings(string s) {
        if(s.size() == '1'){
            return s[0] == '0' ? 0 : 1;
        }

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0')dp[i] = 0;
            else {
                dp[i] = dp[i + 1];
                if(
                    i < n - 1 &&
                    s[i] == '1' ||
                    (s[i] == '2' && s[i + 1] < '7')
                ) {
                    dp[i] += dp[i + 2];
                }
            }
        }



        return dp[0];
    }
};
