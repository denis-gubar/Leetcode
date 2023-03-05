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
    int prev;
    void traverse(TreeNode* root)
    {
        if (!root) return;
        traverse(root->left);        
        result = min(result, root->val - prev);
        prev = root->val;
        traverse(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        prev = -100'000;
        result = 100'000;
        traverse(root);
        return result;
    }
};