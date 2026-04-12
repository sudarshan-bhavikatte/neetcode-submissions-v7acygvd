class Solution {

private:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> V;



    bool dfs(int n, int prev){

        if(V.find(n) != V.end())return false;
        
        V[n] = 1;

        for(auto a : adj[n]){
            if(a != prev){
                if(!dfs(a, n))return false;
            }
        }

        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {

        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        if(!dfs(0, -1)) return false;

        return V.size() == n;
    }
};
