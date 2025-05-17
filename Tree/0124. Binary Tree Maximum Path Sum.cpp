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
    int calc(TreeNode* root)
    {
        int best_sum = 0;
        if (root)
        {
            int left = calc(root->left);
            int right = calc(root->right);
            best_sum = max({ 0, left, right }) + root->val;
            result = max({ result, best_sum, left + right + root->val });
        }
        return best_sum;
    }
    int maxPathSum(TreeNode* root) {
        result = root->val;
        calc(root);
        return result;
    }
};
