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
    pair<int, int> calc(TreeNode* root)
    {
        if (!root) return {0, 0};
        pair<int,int> left = calc(root->left);
        pair<int, int> right = calc(root->right);
        if (root->left && root->left->val - 1 == root->val)
            ++left.second;
        else
            left = { max(left.first, 1), 1 };
        if (root->right && root->right->val - 1 == root->val)
            ++right.second;
        else
            right = { max(right.first, 1), 1 };
        int F = max(left.first, right.first), S = max(left.second, right.second);
        result = max({ result, F, S });
        return { F, S };
    }
    int longestConsecutive(TreeNode* root) {
        result = 0;
        calc(root);
        return result;
    }
};
