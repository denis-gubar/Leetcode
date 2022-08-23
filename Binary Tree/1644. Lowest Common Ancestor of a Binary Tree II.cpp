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
    int calc(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result)
    {
        if (!root) return 0;
        int count = (root == p) + (root == q) + calc(root->left, p, q, result) + calc(root->right, p, q, result);
        if (result == nullptr && count == 2)
            result = root;
        return count;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = nullptr;
        calc(root, p, q, result);
        return result;
    }
};