class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < N; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < N; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        unordered_set<int> v;

        pq.push({0, 0});
        int cost = 0;

        while(v.size() < N){
            auto curr = pq.top(); pq.pop();
            int point = curr.second;
            int c = curr.first;
            if(v.count(point)) continue;
            cost += c;
            v.insert(point);
            for(auto a : adj[point]){
                if(!v.count(a.second))pq.push({a.first, a.second});
            }
        }
    
        return cost;

    }
};
