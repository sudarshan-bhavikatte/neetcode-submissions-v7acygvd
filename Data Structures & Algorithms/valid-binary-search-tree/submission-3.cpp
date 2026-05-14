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
    vector<int> res;

    void preorder(TreeNode* root){
        if(!root) return;

        preorder(root->left);
        res.push_back(root->val);
        preorder(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        
        preorder(root);

        for(int i = 1; i < res.size(); i++){
            if(res[i - 1] >= res[i])return false;
        }

        return true;
    }
};
