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
    int result;
    int const INF = 1 << 20;
    pair<int, int> calc(TreeNode* root, int p, int q)
    {
        pair<int, int> P{INF, INF};
        if (!root)
            return P;
        pair<int, int> L = calc(root->left, p, q);
        pair<int, int> R = calc(root->right, p, q);
        if (root->val == p)
            P.first = 0;
        if (root->val == q)
            P.second = 0;
        P.first = min({L.first + 1, R.first + 1, P.first});
        P.second = min({L.second + 1, R.second + 1, P.second});
        if (result > P.first + P.second)
            result = P.first + P.second;
        return P;
    }
    int findDistance(TreeNode* root, int p, int q) {
        result = INF;
        calc(root, p, q);
        return result;
    }
};