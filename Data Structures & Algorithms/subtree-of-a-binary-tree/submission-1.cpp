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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if (!p && !q)return true;

        if (!p || !q || p->val != q->val){
            return false;
        }

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        bool res = false;

        queue<TreeNode*> queue;

        queue.push(root);

        while(!queue.empty() && !res){
            TreeNode* curr = queue.front();
            queue.pop();
            if (curr->val == subRoot->val){
                res = isSameTree(curr,subRoot);
            }
            if(curr->left){
                queue.push(curr->left);
            }
            if(curr->right){
                queue.push(curr->right);
            }
        }
        return res;
    }
};
