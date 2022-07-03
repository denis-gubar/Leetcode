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
    TreeNode* calc(TreeNode* root, TreeNode*& result)
    {
        if (!root) return nullptr;
        TreeNode* left = calc(root->left, result);
        TreeNode* right = calc(root->right, result);
        if (left)
        {
            left->right = root;
            left->left = right;
            root->left = root->right = nullptr;
            if (!result)
                result = left;
        }
        return root;
    }
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left)
            return root;
        TreeNode* result = nullptr;
        calc(root, result);
        return result;
    }
};
