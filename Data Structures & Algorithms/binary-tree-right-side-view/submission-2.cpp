/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> levels;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int s = q.size();
            vector<int> l;
            while(!q.empty() && s > 0){
                TreeNode* n = q.front();
                q.pop();
                l.push_back(n->val);

                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);

                s--;
            }

            levels.push_back(l);
        }

        vector<int> res;

        for(vector<int> l : levels){
            res.push_back(l[l.size() - 1]);
        }

        return res;
    }
};
