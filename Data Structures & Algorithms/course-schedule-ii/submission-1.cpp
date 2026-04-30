class Solution {
    unordered_map<int, vector<int>> adj;
    vector<int> state;
    vector<int> res;

    bool dfs(int n){
        if(state[n] == 1) return true;
        if(state[n] == 2) return false;
        state[n] = 1;

        for(int p : adj[n]){
            if(dfs(p))return true;
        }
        state[n] = 2;
        res.push_back(n);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto p : prerequisites)adj[p[0]].push_back(p[1]);
        state.assign(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            if(dfs(i))return {};
        }

        return res;
    }
};
