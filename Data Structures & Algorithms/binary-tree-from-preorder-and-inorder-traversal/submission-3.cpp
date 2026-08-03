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
    int idx = 0;
    unordered_map<int, int> idxs;
    TreeNode* dfs(vector<int>& preorder, int i, int j){
        if(i > j)return nullptr;
        int root_val = preorder[idx++];
        TreeNode* root = new TreeNode(root_val);
        int mid = idxs[root_val];
        root->left = dfs(preorder, i, mid - 1);
        root->right = dfs(preorder, mid + 1, j);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            idxs[inorder[i]] = i;
        }

        return dfs(preorder, 0, inorder.size() - 1);
    }
};
