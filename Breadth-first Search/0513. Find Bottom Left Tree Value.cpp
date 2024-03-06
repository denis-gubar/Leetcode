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
    int topLevel;
    void calc(TreeNode* root, int level)
    {
        if (!root) return;
        if (level > topLevel)
            topLevel = level, result = root->val;
        calc(root->left, level + 1);
        calc(root->right, level + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        topLevel = -1;
        calc(root, 0);
        return result;
    }
};
