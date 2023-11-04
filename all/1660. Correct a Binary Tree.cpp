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
    unordered_map<TreeNode*, pair<TreeNode*, int>> M;
    TreeNode* calc(TreeNode* root, TreeNode* parent = nullptr, int level = 0)
    {
        if (!root) return nullptr;
        TreeNode* result = nullptr;
        if (M.find(root) != M.end())
            return M[root].first;
        M[root] = {parent, level};
        result = calc(root->left, root, level + 1);
        if (!result) 
            result = calc(root->right, root, level + 1);
        return result;
    }
    TreeNode* correctBinaryTree(TreeNode* root) {
        TreeNode* badNode = calc(root);
        TreeNode* parentBadNode = M[badNode].first;
        if (parentBadNode->left == badNode)
            parentBadNode->left = nullptr;
        if (parentBadNode->right == badNode)
            parentBadNode->right = nullptr;
        return root;
    }
};