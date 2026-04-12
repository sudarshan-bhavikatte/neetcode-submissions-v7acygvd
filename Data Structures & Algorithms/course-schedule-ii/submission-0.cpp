class Solution {

private:
    unordered_map<int, vector<int>> adj;
    vector<int>state;
    vector<int>res;

    bool dfs(int i){

        if(state[i] == 1) return false;
        if(state[i] == 2) return true;

        state[i] = 1;

        for(int pre : adj[i]){
            if(!dfs(pre)) return false;
        }

        state[i] = 2;
        res.push_back(i);

        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        state.resize(numCourses, 0);

        for(auto p : prerequisites){
            adj[p[0]].push_back(p[1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(!dfs(i)) return {};
        }

        return res;
    }
};
