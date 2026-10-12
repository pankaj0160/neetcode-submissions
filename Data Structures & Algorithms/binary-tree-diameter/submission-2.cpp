class Solution {
private:
    int maxDiameter = 0;

    int height(TreeNode* node) {
        if (node == NULL) return 0;
        
        // Recursively find the height of left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        // Update the global maximum diameter if the path through current node is larger
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        
        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0; // Reset for test cases
        height(root);
        return maxDiameter;
    }
};