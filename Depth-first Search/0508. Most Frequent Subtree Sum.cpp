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
    unordered_map<int, int> M;
    int calc(TreeNode* root)
    {
        if (!root)
            return 0;
        int result = root->val + calc(root->left) + calc(root->right);
        ++M[result];
        return result;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        int best = 0;
        calc(root);
        for (auto [key, value] : M)
            if (best < value)
                best = value;
        for (auto [key, value] : M)
            if (value == best)
                result.push_back(key);
        return result;
    }
};
