/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* result;
    TreeNode* p;
    TreeNode* q;
    int calc(TreeNode* root)
    {
        if (!root) return 0;
        int sum = (root == p) + (root == q) + calc(root->left) + calc(root->right);
        if (sum == 2 && !result)
            result = root;
        return sum;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        result = nullptr;
        this->p = p, this->q = q;
        calc(root);
        return result;
    }
};
