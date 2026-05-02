class Solution {
    string text1;
    string text2;
    int s1;
    int s2;
    vector<vector<int>> memo;
    int dfs(int i, int j){
        if(i == s1 || j == s2)return 0;

        if(memo[i][j] != -1)return memo[i][j];

        if(text1[i] == text2[j])memo[i][j] = 1 + dfs(i + 1, j + 1);
        else memo[i][j] = max(dfs(i + 1, j), dfs(i, j + 1));

        return memo[i][j];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();

        this->text1 = text1;
        this->text2 = text2;
        this->s1 = s1;
        this->s2 = s2;
        memo.assign(s1, vector<int>(s2, -1));
        return dfs(0,0);
    }
};
