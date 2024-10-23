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
    pair<bool, int> calc(TreeNode* root)
    {
        if (!root)
            return { true, 0 };
        pair<bool, int> L = calc(root->left);
        pair<bool, int> R = calc(root->right);
        pair<bool, int> result{ L.first && R.first && L.second == R.second, L.second + R.second + 1};
        if (result.first)
            A.push_back(result.second);
        return result;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        A.reserve(2'000);
        calc(root);
        if (A.size() < k)
            return -1;
        sort(A.begin(), A.end(), greater<int>{});
        return A[k - 1];
    }
};
