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
    unordered_map<TreeNode*, int> memo;
public:
    int dfs(TreeNode* root) {
        if(memo.count(root))return memo[root];
        if(!root)return 0;

        int res = root->val;
        if(root->left){
            res += dfs(root->left->left) + dfs(root->left->right);
        }
        if(root->right){
            res += dfs(root->right->left) + dfs(root->right->right);
        }

        res = max(dfs(root->left) + dfs(root->right), res);
        memo[root] = res;
        return res;
    }

    int rob(TreeNode* root){
        return dfs(root);
    }
};