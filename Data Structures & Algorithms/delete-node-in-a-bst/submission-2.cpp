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
    TreeNode* dfs(TreeNode* root, int key){
        if(!root) return root;

        if(key > root->val){
            root->right = dfs(root->right, key);
        }
        else if(key < root->val){
            root->left = dfs(root->left, key);
        } else {
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            TreeNode* cur = root->right;
            while(cur->left){
                cur = cur->left;
            }
            root->val = cur->val;
            root->right = dfs(root->right, root->val);   
        }
        return root;
    } 
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        return dfs(root, key);
    }
};