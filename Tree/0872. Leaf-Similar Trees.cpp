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
    void calc(vector<int>& result, TreeNode* root)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            result.push_back(root->val);
        else
            calc(result, root->left), calc(result, root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> A, B;
        A.reserve(100);
        B.reserve(100);
        calc(A, root1);
        calc(B, root2);
        return A == B;
    }
};
