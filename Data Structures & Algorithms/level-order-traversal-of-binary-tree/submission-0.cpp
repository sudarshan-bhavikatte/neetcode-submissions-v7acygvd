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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> res;
        deque<TreeNode*> dq;
        dq.push_back(root);

        while(!dq.empty()){
            vector<int> eles;
            int levelSize = dq.size();
            for (int i=0;i<levelSize;i++){

                TreeNode* node = dq.front();
                eles.push_back(node->val);
                dq.pop_front();

                if(node->left)dq.push_back(node->left);
                if(node->right)dq.push_back(node->right);
            }
            res.push_back(eles);
        }

        return res;
    }
};
