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
    long long const INF = 1LL << 50;
    int limit;
    pair<TreeNode*, long long> calc(TreeNode* root, long long total)
    {
        if (!root)
            return { nullptr, -INF };
        if (!root->left && !root->right)
            return { total + root->val < limit ? nullptr : root, root->val };
        pair<TreeNode*, long long> left = calc(root->left, total + root->val);
        root->left = left.first;
        pair<TreeNode*, long long> right = calc(root->right, total + root->val);
        root->right = right.first;
        if (!left.first && !right.first)
            return { nullptr, max(left.second, right.second) + root->val };
        return {root, max(left.second, right.second) + root->val };        
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        this->limit = limit;
        return calc(root, 0LL).first;
    }
};
