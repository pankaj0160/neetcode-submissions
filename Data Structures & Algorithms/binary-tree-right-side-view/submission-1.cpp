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
    vector<int> rightSideView(TreeNode* root) {
        // printing last nodes of each level

        if(root==NULL) return {};

        vector<int> ans;

        queue<TreeNode*> q;

        q.push(root);

        TreeNode* temp = root;

        while (!q.empty()) {
            int _size = q.size();
            int count = 0;

            for (int i = 0; i < _size; i++) {
                if (count == _size - 1) ans.push_back(q.front()->val);
                TreeNode* popped = q.front();
                q.pop();
                count++;
                if (popped->left) q.push(popped->left);
                if (popped->right) q.push(popped->right);
            }
        }
        return ans;
    }
};
