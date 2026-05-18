class Solution {
    vector<int> matchsticks;
    vector<int> sides;
    int l;
    bool dfs(int idx){

        if(idx >= matchsticks.size()) return true;


        for(int i = 0; i < 4; i++){
            if(sides[i] + matchsticks[idx] <= l){
                sides[i] += matchsticks[idx];
                if(dfs(idx + 1)) return true;
                sides[i] -= matchsticks[idx];
            }
        }

        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalLength = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        this->matchsticks = matchsticks;
        this->l = totalLength / 4;
        sides.assign(4, 0);

        if(totalLength % 4 != 0) return false;

        sort(matchsticks.rbegin(), matchsticks.rend());


        return dfs(0);
    }
};