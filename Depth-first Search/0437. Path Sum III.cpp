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
    unordered_map<long long, int> M;
    int targetSum;
    int calc(TreeNode* root, long long sum = 0)
    {
        if (!root)
            return 0;
        sum += root->val;
        int result = 0;
        ++M[sum];
        if (auto it = M.find(sum - targetSum); it != M.end())
            result += it->second - (targetSum == 0);
        result += calc(root->left, sum);
        result += calc(root->right, sum);
        --M[sum];
        return result;
    }
    int pathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        M.clear();
        ++M[0];
        return calc(root);
    }
};
