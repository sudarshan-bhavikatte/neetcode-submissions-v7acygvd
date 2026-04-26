class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, int> res;

        unordered_map<int, vector<pair<int, int>>> adj;

        // for (int i = 0; i < n; i++) {
        //     adj[i] = vector<pair<int, int>>();
        // }

        for(vector<int> e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<
            pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int, int>>
            > pq;

        pq.push({0,src});
        

        while(!pq.empty()){
            pair<int, int> top = pq.top();
            pq.pop();

            int w = top.first;
            int node = top.second;

            if(res.find(node) != res.end()) continue;
            res[node] = w;

            for(auto a : adj[node]){
                if(res.find(a.first) == res.end()) pq.push({a.second + w, a.first});
            }
        }

        for (int i = 0; i < n; i++) {
            if (res.find(i) == res.end()) {
                res[i] = -1;
            }
        }


        return res;
    }
};
