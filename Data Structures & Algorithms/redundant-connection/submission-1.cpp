class Solution {
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
public:
    int find_parent(int node){
        if(node != parent[node]){
            parent[node] = find_parent(parent[node]);
        }
        return parent[node];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> res;
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            rank[i] = 0;
        }

        for(int i = 0; i < n; i++){
            int from = edges[i][0];
            int to = edges[i][1];

            int p1 = find_parent(from);
            int p2 = find_parent(to);

            if(p1 == p2){
                res.push_back(edges[i]);
            } else {
                if(rank[p1] > rank[p2]){
                    parent[p2] = p1;
                }
                else if(rank[p2] > rank[p1]){
                    parent[p1] = p2;
                }
                else {
                    parent[p2] = p1;
                    rank[p1]++;
                }
            }
        }

        return res.back();
    }
};
