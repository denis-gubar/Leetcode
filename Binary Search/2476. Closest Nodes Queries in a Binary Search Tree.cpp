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
    void calc(TreeNode* root)
    {
        if (!root) return;
        calc(root->left);
        A.push_back(root->val);
        calc(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int N = queries.size();
        vector<vector<int>> result(N);
        A.clear();
        calc(root);
        for (int i = 0; i < N; ++i)
        {
            int const& value = queries[i];
            result[i] = { -1, -1 };
            auto it = lower_bound(A.begin(), A.end(), value);
            if (it != A.end())
            {
                result[i][1] = *it;
                if (*it == value)
                    result[i][0] = *it;
            }
            if ((it == A.end() || *it != value) && it != A.begin())
                result[i][0] = *prev(it);
        }
        return result;
    }
    vector<int> A;
};
