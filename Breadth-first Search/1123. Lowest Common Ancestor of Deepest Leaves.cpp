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
    unordered_set<TreeNode*> S;
    int maxDepth;
    TreeNode* result;
    int caldDepth(TreeNode* root)
    {
        if (!root) return 0;
        return 1 + max(caldDepth(root->left), caldDepth(root->right));
    }
    bool mark(TreeNode* root, int level = 1)
    {
        if (!root) return false;
        bool result = level == maxDepth;
        result |= mark(root->left, level + 1); 
        result |= mark(root->right, level + 1);
        if (result)
            S.insert(root);
        return result;
    }
    void calc(TreeNode* root)
    {
        bool hasLeft = S.find(root->left) != S.end();
        bool hasRight = S.find(root->right) != S.end();
        if (hasLeft && hasRight || !hasLeft && !hasRight)
        {
            result = root;
            return;
        }
        if (hasLeft)
            calc(root->left);
        if (hasRight)
            calc(root->right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return root;
        maxDepth = caldDepth(root);
        mark(root);
        calc(root);
        return result;
    }
};
