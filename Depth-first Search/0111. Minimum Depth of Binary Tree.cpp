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
    int minDepth( TreeNode* root ) {
        if (root)
        {
            if (!root->left && !root->right)
                return 1;
            return min( root->left ? minDepth( root->left ) + 1 : INT_MAX, root->right ? minDepth( root->right ) + 1 : INT_MAX );
        }
        return 0;
    }
};