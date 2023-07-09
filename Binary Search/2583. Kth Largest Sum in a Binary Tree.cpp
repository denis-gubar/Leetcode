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
    void calc(TreeNode* root, vector<vector<int>>& result, int level)
    {
        if (result.size() == level)
            result.push_back(vector<int>());
        result[level].push_back(root->val);
        if (root->left)
            calc(root->left, result, level + 1);
        if (root->right)
            calc(root->right, result, level + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<vector<int>> result;
        if (root)
            calc(root, result, 0);
        vector<long long> A;
        for (vector<int> const& row : result)
            A.push_back(accumulate(row.begin(), row.end(), 0LL));
        int N = A.size();
        if (N < k)
            return -1;
        sort(A.begin(), A.end(), greater<>{});
        return A[k - 1];
    }
};
