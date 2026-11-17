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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> traverse_list;

        if (!root) return nullptr;
        traverse_list.push(root);

        while (!traverse_list.empty()) {
            TreeNode* cur_node = traverse_list.front();
            traverse_list.pop();

            swap(cur_node->left, cur_node->right);

            if (cur_node->left) traverse_list.push(cur_node->left);
            if (cur_node->right) traverse_list.push(cur_node->right); 
        }

        return root;
    }
};
