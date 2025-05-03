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
    int prev(TreeNode* root)
    {
        root = root->left;
        while (root->right)
            root = root->right;
        return root->val;
    }
    int next(TreeNode* root)
    {
        root = root->right;
        while (root->left)
            root = root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key)
        {
            if (!root->left && !root->right)
                return nullptr;
            else if (root->right)
            {
                root->val = next(root);
                root->right = deleteNode(root->right, root->val);
            }
            else
            {
                root->val = prev(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        return root;
    }
};
