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
    void inorder(TreeNode* root, vector<int>& smallest){
        if(!root){
            return;
        }
        inorder(root->left, smallest);
        smallest.push_back(root->val);
        inorder(root->right, smallest);
    }
public:
    int kthSmallest(TreeNode* root, int k) {

        vector<int> smallest;
        inorder(root, smallest);

        return smallest[k - 1];
    }
};
