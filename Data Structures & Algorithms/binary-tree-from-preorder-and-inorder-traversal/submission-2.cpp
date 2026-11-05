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

    int find(vector<int>& inorder, int k, int i, int j) {
        while(i <= j) {
            if(inorder[i] == k) return i;
            i++;
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 
                      preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int i, int j, int p, int q) {

        if(i > j || p > q) return NULL;

        TreeNode* root = new TreeNode(preorder[i]);

        int mid = find(inorder, preorder[i], p, q);

        int leftSize = mid - p;

        root->left = helper(preorder, inorder,
                            i+1, i+leftSize,
                            p, mid-1);

        root->right = helper(preorder, inorder,
                             i+leftSize+1, j,
                             mid+1, q);

        return root;
    }
};