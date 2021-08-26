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
    void calc( TreeNode* root, vector<vector<int>>& result, int level )
    {
        if (result.size() == level)
            result.push_back( vector<int>() );
        result[level].push_back( root->val );
        if (root->left)
            calc( root->left, result, level + 1 );
        if (root->right)
            calc( root->right, result, level + 1 );
    }
    vector<vector<int>> levelOrderBottom( TreeNode* root ) {
        vector<vector<int>> result;
        if (root)
            calc( root, result, 0 );
        reverse( result.begin(), result.end() );
        return result;
    }
};