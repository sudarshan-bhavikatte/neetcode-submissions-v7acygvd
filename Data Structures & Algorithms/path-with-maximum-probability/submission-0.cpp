/*
1. given an undirected weighted graph of n nodes (0-indexed),
2. edges[i] = [a, b]
3. probability of success of traversing that edge succProb[i].

to return :
1. max prob of success from start to end
2. 0 if no path

sol :
1. create a adj_list using hashing
2. a priority_queue can be used
3. probs are multiplied.

*/

class Solution {
   public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb,
                          int start_node, int end_node) {

        unordered_map<int, vector<pair<double, int>>> adj;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({p, v});
            adj[v].push_back({p, u});
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        unordered_map<int, int> V;

        pq.push({1.00, start_node});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int node = curr.second;
            double p = curr.first;

            if (V.find(node) != V.end()) continue;
            V[node]++;

            if (node == end_node) return p;

            for (auto n : adj[node]) {
                int n_node = n.second;
                double n_p = n.first;

                pq.push({p * n_p, n_node});
            }
        }

        return 0;
    }
};