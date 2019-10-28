/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree( TreeNode* root ) {
        if (root == nullptr)
            return root;
        if (root->left)
            root->left = pruneTree( root->left );
        if (root->right)
            root->right = pruneTree( root->right );
        if (!root->left && !root->right && !root->val)
        {
            delete root;
            root = nullptr;
        }
        return root;
    }
};