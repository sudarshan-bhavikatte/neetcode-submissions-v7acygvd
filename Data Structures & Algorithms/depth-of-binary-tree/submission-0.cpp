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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        int res = 0;
        q.push({root, 1});
        while(!q.empty()){
            auto [cur, lvl] = q.front();
            q.pop();
            res = lvl;
            if(cur->right)q.push({cur->right, lvl + 1});
            if(cur->left)q.push({cur->left, lvl + 1});
        }

        return res;
    }
};
