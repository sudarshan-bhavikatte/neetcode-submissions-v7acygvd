class Solution {
    unordered_map<int, vector<int>> adj;
    unordered_set<int> visited;

    void dfs(int node){

        if(visited.count(node) == 1) return;

        visited.insert(node);

        for(int n : adj[node]){
            dfs(n);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            if(visited.count(i) != 1){
                dfs(i);
                count++;
            }
        }

        return count;
    }
};
