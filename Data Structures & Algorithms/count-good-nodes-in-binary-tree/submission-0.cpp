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
    int dfs(TreeNode* root, int maxval) {
        if (root == NULL) return 0;

        bool isgood = (root->val >= maxval);

        int newmax = max(maxval, root->val);

        return (isgood ? 1 : 0) + dfs(root->left, newmax) + dfs(root->right, newmax);
    }
    int goodNodes(TreeNode* root) { return dfs(root, root->val); }
};
