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
    void dfs(TreeNode* node, int depth, vector<int> *res){
        if(!node){
            return;
        }

        if(res->size() == depth){
            res->push_back(node->val);
        }
        if(node->right)dfs(node->right, depth + 1, res);
        if(node->left)dfs(node->left, depth + 1, res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int> res;
        dfs(root,0,&res);

        return res;

    }
};
