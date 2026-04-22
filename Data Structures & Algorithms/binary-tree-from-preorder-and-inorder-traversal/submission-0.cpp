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
    int pre_idx = 0;
    TreeNode* dfs(vector<int> preorder, unordered_map<int, int>& idx, int s, int e) {
        if (s > e) return nullptr;
        
        int val = preorder[pre_idx++];
        TreeNode* node = new TreeNode(val);

        int m = idx[val];

        node->left = dfs(preorder, idx, s, m - 1);        
        node->right = dfs(preorder, idx, m + 1, e);

        return node;        
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> idx;

        for (int i = 0; i < inorder.size(); i++) {
            idx[inorder[i]] = i;
        }

        return dfs(preorder, idx, 0, inorder.size() - 1);
    }
};
