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
    int ans = 0;
    int i = 0;
    int kthSmallest(TreeNode* root, int k) {
        // inorder traversal
        if (root == NULL) return -1;

        kthSmallest(root->left, k);
        i++;
        if (i == k) ans = root->val;
        kthSmallest(root->right, k);

        return ans;
    }
};
