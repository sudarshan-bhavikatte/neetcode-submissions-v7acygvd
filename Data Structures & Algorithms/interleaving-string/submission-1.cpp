class Solution {
private:
    vector<vector<int>> memo;

    bool dfs(int i, int j, const string& s1, const string& s2, const string& s3) {
        if (i == s1.size() && j == s2.size())
            return true;

        if (memo[i][j] != -1)
            return memo[i][j];

        int k = i + j;
        bool ans = false;

        if (i < s1.size() && s1[i] == s3[k])
            ans = dfs(i + 1, j, s1, s2, s3);

        if (!ans && j < s2.size() && s2[j] == s3[k])
            ans = dfs(i, j + 1, s1, s2, s3);

        memo[i][j] = ans;
        return ans;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size())
            return false;

        memo.assign(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        return dfs(0, 0, s1, s2, s3);
    }
};
