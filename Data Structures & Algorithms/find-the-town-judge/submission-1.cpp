class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inOrder(n, 0);
        vector<int> outOrder(n, 0);

        for(int i = 0; i < trust.size(); i++){
            outOrder[trust[i][0] - 1]++;
            inOrder[trust[i][1] - 1]++;
        }

        for(int i = 0; i < n; i++){
            if(inOrder[i] == n -1 && outOrder[i] == 0) return i + 1;
        }

        return -1;
    }
};