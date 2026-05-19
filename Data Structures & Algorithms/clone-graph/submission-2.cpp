/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> map;

    Node* dfs(Node* node){
        if(node == nullptr) return nullptr;

        if(map.find(node) != map.end()) return map[node];

        Node* cp = new Node(node->val);
        map[node] = cp;
        for(auto neigh : node->neighbors){
            cp->neighbors.push_back(dfs(neigh));
        }

        return cp;
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
