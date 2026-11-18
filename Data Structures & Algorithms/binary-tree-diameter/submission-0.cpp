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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        int temp = dfs(root, diameter);
        return diameter;
    }
private:
    int dfs(TreeNode* root, int& diameter) {
        if (root == nullptr) return 0;
        int left_len = dfs(root->left, diameter);
        int right_len = dfs(root->right, diameter);
        diameter = max(diameter, left_len + right_len); // update the maximum diameter at current node
        return 1 + max(left_len, right_len);
    }
};
