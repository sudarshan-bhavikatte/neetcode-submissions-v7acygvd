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
private:
    vector<int> dfs(TreeNode* root){
        if(!root) return {1, 0};

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        vector<int> res(2, 0);

        res[0] = (left[0] == 1 && 
            right[0] == 1 && 
            abs(left[1] - right[1]) <= 1
            ) ? 1 : 0;

        res[1] = max(left[1], right[1]) + 1;

        return res;
    }
public:
    bool isBalanced(TreeNode* root) {
        vector<int> res = dfs(root);

        return res[0] == 1;
    }
};
