class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(string word1, string word2, int i, int j){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(j) != memo[i].end()){
                return memo[i][j];
            }
        }
        if(i == word1.size())return word2.size() - j;
        if(j == word2.size())return word1.size() - i;

        int res = INT_MAX;
        if(word1[i] == word2[j]){
            res = dfs(word1, word2, i + 1, j + 1);
        }
        else {
            int replace = 1 + dfs(word1, word2, i + 1, j + 1);
            int del = 1 + dfs(word1, word2, i, j + 1);
            int ins = 1 + dfs(word1, word2, i + 1, j);

            res = min({replace, del, ins}); 
        }

        memo[i][j] = res;
        return res;
    }
public:
    int minDistance(string word1, string word2) {
        return dfs(word1, word2, 0, 0);
    }
};
