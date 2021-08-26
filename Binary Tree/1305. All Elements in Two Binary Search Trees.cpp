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
    void calc(TreeNode* root, vector<int>& A)
    {
        if (!root) return;
        calc(root->left, A);
        A.push_back(root->val);
        calc(root->right, A);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        vector<int> A, B;
        calc(root1, A);
        calc(root2, B);
        merge(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));
        return result;
    }
};