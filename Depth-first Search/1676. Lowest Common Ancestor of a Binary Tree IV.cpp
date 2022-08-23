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
    int calc(TreeNode* root, unordered_set<TreeNode*> const& S, TreeNode*& result)
    {
        if (!root) return 0;
        int count = (S.find(root) != S.end()) + 
            calc(root->left, S, result) + calc(root->right, S, result);
        if (count == S.size() && result == nullptr)
            result = root;
        return count;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> S(nodes.begin(), nodes.end());
        TreeNode* result = nullptr;
        calc(root, S, result);
        return result;
    }
};