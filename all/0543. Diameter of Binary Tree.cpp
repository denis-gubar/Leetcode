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
    int result;
    int calc( TreeNode* root )
    {
        int depth = 0;
        if (root)
        {
            int left_depth = calc( root->left );
            int right_depth = calc( root->right );
            result = max( result, left_depth + right_depth );
            depth = max( left_depth, right_depth ) + 1;
        }
        return depth;
    }
    int diameterOfBinaryTree( TreeNode* root ) {
        result = 0;
        calc( root );
        return result;
    }
};