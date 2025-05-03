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
    vector<int> result;
    void calc(TreeNode* root, int level = 0)
    {
        if (!root) return;
        if (result.size() == level)
            result.push_back(root->val);
        calc(root->left, level + 1);
        result[level] = root->val;
        calc(root->right, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        result.clear();
        calc(root);
        return result;
    }
};
