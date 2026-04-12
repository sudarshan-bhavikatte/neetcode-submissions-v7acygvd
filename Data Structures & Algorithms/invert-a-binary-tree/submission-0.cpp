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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        queue<TreeNode*> queue;

        queue.push(root);

        while(!queue.empty()){
            TreeNode* curr = queue.front();
            queue.pop();

            swap(curr->left,curr->right);

            if(curr->left) queue.push(curr->left);
            if(curr->right) queue.push(curr->right);
        }
        return root;

    }
};
