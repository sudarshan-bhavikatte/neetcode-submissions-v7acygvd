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
    int res = 0;

    void dfs(TreeNode* root, int m){
        if(!root) return;

        if(root->val >= m){
            cout << root->val << " ";
            res++;
        }

        dfs(root->left, max(root->val, m));
        dfs(root->right, max(root->val, m));

        return;
    }

public:
    int goodNodes(TreeNode* root) {

        dfs(root, INT_MIN);

        return res;
    }
};
