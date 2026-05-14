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
    unordered_map<int, int> hash;

    TreeNode* dfs(vector<int> preorder, int& i, int l, int r){
        if(l > r) return nullptr;

        int val = preorder[i];
        TreeNode* node = new TreeNode(val);
        int mid = hash[val];
        i++;
        node->left = dfs(preorder, i, l, mid - 1);
        node->right = dfs(preorder, i, mid + 1, r);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)hash[inorder[i]] = i;    
        int s = 0;
        return dfs(preorder, s, 0, inorder.size() - 1);
    }
};
