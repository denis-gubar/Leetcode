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
    int result;
    long long calc(TreeNode* root)
    {
        if (!root) return 0;
        long long children = calc(root->left) + calc(root->right);
        if (root->val == children)
            ++result;
        return root->val + children;
    }
    int equalToDescendants(TreeNode* root) {
        result = 0;
        calc(root);
        return result;
    }
};
