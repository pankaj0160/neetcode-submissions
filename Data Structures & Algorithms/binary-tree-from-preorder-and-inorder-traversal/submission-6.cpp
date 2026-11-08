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
              unordered_map<int, int> mp;

                  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
                          // Store indices of inorder elements for O(1) lookup
                                  for(int i = 0; i < inorder.size(); i++){
                                              mp[inorder[i]] = i;
                                                      }

                                                              return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
                                                                  }

                                                                      TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int i, int j, int p, int q) {
                                                                              if(i > j || p > q) return nullptr;

                                                                                      TreeNode* root = new TreeNode(preorder[i]);

                                                                                              // Get the root index in inorder from the map
                                                                                                      int mid = mp[preorder[i]];
                                                                                                              int leftSize = mid - p;

                                                                                                                      root->left = helper(preorder, inorder,
                                                                                                                                                  i + 1, i + leftSize,
                                                                                                                                                                              p, mid - 1);

                                                                                                                                                                                      root->right = helper(preorder, inorder,
                                                                                                                                                                                                                   i + leftSize + 1, j,
                                                                                                                                                                                                                                                mid + 1, q);

                                                                                                                                                                                                                                                        return root;
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                            };
