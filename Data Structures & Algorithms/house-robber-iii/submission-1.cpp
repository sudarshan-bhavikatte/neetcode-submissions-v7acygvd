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
    unordered_map<TreeNode*, int> cache;

    int dfs(TreeNode* root){
        if(cache.find(root) != cache.end())return cache[root];

        int res = root->val;

        if(root->left){
            res += dfs(root->left->left) + dfs(root->left->right);
        }
        if(root->right){
            res += dfs(root->right->left) + dfs(root->right->right);
        }

        res = max(res, dfs(root->left) + dfs(root->right));
        cache[root] = res;

        return res;
    }

public:
    int rob(TreeNode* root) {

        cache[nullptr] = 0;
        return dfs(root);    
    };
};