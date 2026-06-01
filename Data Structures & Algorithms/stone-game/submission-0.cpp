/*
    given even length piles of stones
    sum of all stones in plie in odd hence no ties

    at each turn:
        choose a pile from start or end
    continue till end;
    winner : person with with most stones

    if alice starts return if alice can win.

    sol : 
    1. decision tree
    2. must choose from start or end
    3. so we can choose either s or e and move pointers
    4. until s <= e
        if(sum >= total / 2 + 1)return true else false;
*/
    
    int dfs(vector<int>& piles, int s, int e, int need, int turn){
        if(s >= e){
            return need <= 0;
        }
        bool res = false;
        if(turn){
            if(piles[s] > piles[e]){
                res = dfs(piles, s + 1, e, need - piles[s], false);
            } else if(piles[s] < piles[e]){
                res = dfs(piles, s, e - 1, need - piles[e], false);
            } else {
                res = dfs(piles, s, e - 1, need - piles[e], false) || 
                    dfs(piles, s + 1, e, need - piles[s], false);
            }
        } else {
            if(piles[s] >= piles[e]){
                res = dfs(piles, s, e - 1, need - piles[e], true);
            } else if(piles[s] < piles[e]){
                res = dfs(piles, s + 1, e, need - piles[s], true);
            } else {
                res = dfs(piles, s + 1, e, need - piles[s], true) || 
                    dfs(piles, s, e - 1, need - piles[e], true);
            }
        }

        return res;
    }
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(), piles.end(), 0);
        int need = (total / 2) + 1;
        return dfs(piles, 0, piles.size() - 1, need, true);
    }
};