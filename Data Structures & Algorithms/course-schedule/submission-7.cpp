class Solution {
    unordered_set<int> v;
    unordered_map<int, vector<int>> adj;

    bool dfs(int n){
        if(v.count(n)) return true;
        if(adj[n].empty()) return false;
        v.insert(n);

        for(auto p : adj[n]){
            if(dfs(p))return true;
        }
        v.erase(n);
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        for(auto p : prerequisites){
            adj[p[0]].push_back(p[1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(dfs(i)) return false;
        }
        return true;        
    }
};
