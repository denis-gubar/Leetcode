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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if (!root)
            return { nullptr, nullptr };
        if (root->val > target)
        {
            auto left = splitBST(root->left, target);
            root->left = left[1];
            return { left[0], root };
        }
        auto right = splitBST(root->right, target);
        root->right = right[0];
        return { root, right[1] };
    }
};
