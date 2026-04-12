class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<int> state;

    bool dfs(int i){
        
            if(state[i] == 1) return false;
            if(state[i] == 2) return true;

            state[i] = 1;
            
            for(int preReq : adj[i]){
                if(!dfs(preReq)) return false;
            }
            state[i] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        state.resize(numCourses, 0);

        for(int i =0; i < prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int preReq = prerequisites[i][1];

            adj[course].push_back(preReq);
        }

        

        for(int i = 0; i < numCourses; i++){
            if(!dfs(i))return false;
        }

        return true;
    }
};
