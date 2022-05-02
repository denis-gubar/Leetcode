/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void calc(TreeNode* root, string& path, vector<string>& result)
    {
        if (!root)
            return;
        int prevSize = path.size();
        path += "->";
        path += to_string(root->val);
        if (!root->left && !root->right)
            result.push_back(path);
        calc(root->left, path, result);
        calc(root->right, path, result);
        path.resize(prevSize);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root)
        {
            string path = to_string(root->val);
            if (!root->left && !root->right)
                result.push_back(path);
            else
            {
                calc(root->left, path, result);
                calc(root->right, path, result);
            }
        }
        return result;
    }
};