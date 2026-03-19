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
    vector<int> A;
    void calc(TreeNode* root, int level, int L)
    {
        if (!root)
            return;
        if (level == L)
            A.push_back(root->val);
        else if (level > L)
            calc(root->left, level, L + 1),
            calc(root->right, level, L + 1);
    }
    int levelMedian(TreeNode* root, int level) {
        A.clear();
        calc(root, level, 0);
        if (A.empty())
            return -1;
        int const N = A.size();
        nth_element(A.begin(), A.begin() + N / 2, A.end());
        return A[N / 2];
    }
};
