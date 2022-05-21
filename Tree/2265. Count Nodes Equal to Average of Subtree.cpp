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
    int Result;
    pair<int, int> calc(TreeNode* root)
    {
        if (!root) return {0, 0};
        pair<int, int> result = calc(root->left);
        pair<int, int> p = calc(root->right);
        result.first += p.first + root->val;
        result.second += p.second + 1;
        if (root->val == result.first / result.second)
            ++Result;
        return result;
    }
    int averageOfSubtree(TreeNode* root) {
        Result = 0;
        calc(root);
        return Result;
    }
};
