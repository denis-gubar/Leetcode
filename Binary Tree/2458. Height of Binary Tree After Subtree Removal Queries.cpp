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
static int D[100'001];
static int L[100'001];
static int R[100'001];
static int Q[100'001];
class Solution {
public:
    pair<int, int> calc(TreeNode* root, int level = 0)
    {
        pair<int, int> result{ 0, 0 };
        int const& V = root->val;
        D[V] = level;
        if (root->left)
        {
            pair<int, int> left = calc(root->left, level + 1);
            result.first = max(left.first, left.second) + 1;
        }
        if (root->right)
        {
            pair<int, int> right = calc(root->right, level + 1);
            result.second = max(right.first, right.second) + 1;
        }
        L[V] = result.first;
        R[V] = result.second;
        return result;
    }
    void calc2(TreeNode* root, int other)
    {
        int const& V = root->val;
        Q[V] = other;
        if (root->left)
            calc2(root->left, max(R[V] + D[V], other));
        if (root->right)
            calc2(root->right, max(L[V] + D[V], other));
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int const N = queries.size();
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        calc(root);
        if (root->left)
            calc2(root->left, R[root->val]);
        if (root->right)
            calc2(root->right, L[root->val]);
        vector<int> result(N);
        for (int q = 0; q < N; ++q)
            result[q] = Q[queries[q]];
        return result;
    }
};
