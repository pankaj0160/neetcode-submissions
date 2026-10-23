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
        // bfs traversal : level by level

        if (root == NULL) return {};

        vector<vector<int>> ans;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int levelsize = q.size();

            vector<int> subans;

            for (int i = 0; i < levelsize; i++) {
                TreeNode* popped = q.front();
                q.pop();
                subans.push_back(popped->val);
                if (popped->left) q.push(popped->left);
                if (popped->right) q.push(popped->right);
            }
            ans.push_back(subans);
        }
        return ans;
    }
};
