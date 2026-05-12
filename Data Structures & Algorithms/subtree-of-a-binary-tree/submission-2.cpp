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
    // Helper function to check if two trees are identical
    bool isIdentical(TreeNode* node1, TreeNode* node2) {
        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({node1, node2});

        while (!s.empty()) {
            auto [n1, n2] = s.top();
            s.pop();

            // If both are null, this branch matches
            if (!n1 && !n2) continue;
            // If only one is null, or values differ, they don't match
            if (!n1 || !n2 || n1->val != n2->val) return false;

            s.push({n1->left, n2->left});
            s.push({n1->right, n2->right});
        }
        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();

            // Every time we find a value match, we test the whole identity
            if (cur->val == subRoot->val) {
                if (isIdentical(cur, subRoot)) return true;
            }

            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
        }

        return false;
    }
};