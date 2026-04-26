class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, int> res;

        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto t : times){
            adj[t[0]].push_back({t[1], t[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0,k});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int w = curr.first;
            int node = curr.second;

            if(res.find(node) != res.end()) continue;
            res[node] = w;

            for(auto a : adj[node]){
                int new_node = a.first;
                int we = a.second;

                if(res.find(new_node) == res.end()){
                    pq.push({w + we, new_node});
                }
            }
        }

        if(res.size() != n) return -1;
        int min_time = INT_MIN;

        for(auto it = res.begin(); it != res.end(); it++){
            min_time = max(it->second, min_time);
        }

        return min_time;
    }
};
