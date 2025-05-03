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
    int goodNodes(TreeNode* root, int prevMax = -10'000) {
        if (!root) return 0;
        return (prevMax <= root->val) + goodNodes(root->left, max(root->val, prevMax)) + goodNodes(root->right, max(root->val, prevMax));
    }
};
