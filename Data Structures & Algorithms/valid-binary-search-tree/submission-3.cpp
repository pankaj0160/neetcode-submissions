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
    bool valid(TreeNode* root, TreeNode* lo, TreeNode* hi) {
        if (!root) return true;

        if (lo && root->val <= lo->val) return false;
        if (hi && root->val >= hi->val) return false;

        return valid(root->left, lo, root) && valid(root->right, root, hi);
    }
    bool isValidBST(TreeNode* root) { return valid(root, NULL, NULL); }
};
