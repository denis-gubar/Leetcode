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
    void calc(TreeNode* root, vector<vector<int>>& result, int level = 0)
    {
        if (!root)
            return;
        if (result.size() == level)
            result.push_back({ root->val });
        else
            result[level].push_back(root->val);
        calc(root->left, result, level + 1);
        calc(root->right, result, level + 1);
    }
    void calc2(TreeNode*& root, vector<vector<int>>& result, int level = 0)
    {
        if (!root)
            return;
        if (level % 2 == 1)
        {
            root->val = result[level].back();
            result[level].pop_back();
        }
        calc2(root->left, result, level + 1);
        calc2(root->right, result, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<int>> result;
        calc(root, result);
        calc2(root, result);
        return root;
    }
};
