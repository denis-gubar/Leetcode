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
    void calc(TreeNode* root, TreeNode*& prev)
    {
        if (!root) return;
        if (prev)
            prev->right = root;
        prev = root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = nullptr;
        root->right = nullptr;
        calc(left, prev);
        calc(right, prev);
    }
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        calc(root, prev);
    }
};