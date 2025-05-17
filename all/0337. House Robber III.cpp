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
    pair<int, int> calc(TreeNode* root)
    {
        if (!root) return {};
        pair<int, int> result{};
        pair<int, int> left = calc(root->left);
        pair<int, int> right = calc(root->right);
        result.first = max(left.first, left.second) + max(right.first, right.second);
        result.second = root->val + left.first + right.first;
        return result;
    }
    int rob(TreeNode* root) {
        pair<int, int> result = calc(root);
        return max(result.first, result.second);
    }
};
