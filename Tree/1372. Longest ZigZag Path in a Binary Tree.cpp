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
        if (!root) return { 0, 0 };
        pair<int, int> P = { 1 + calc(root->left).second, 1 + calc(root->right).first };
        result = max({ result, P.first, P.second });
        return P;
    }
    int longestZigZag(TreeNode* root) {
        result = 0;
        calc(root);
        return result - 1;
    }
};
