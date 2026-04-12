class Solution {
    int dfs(int i, int j, string word1, string word2){

        if(i == word1.size())return word2.size() - j;
        if(j == word2.size())return word1.size() - i;

        if(word1[i] == word2[j]){
            return dfs(i+1, j+1, word1, word2);
        }

        int res = std::min(
            dfs(i+1, j, word1, word2),
            dfs(i, j+1, word1, word2)
        );

        res = std::min(res, dfs(i+1, j+1, word1, word2));

        return res + 1;
    }
public:
    int minDistance(string word1, string word2) {
        return dfs(0,0,word1,word2);
    }
};
