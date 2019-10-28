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
    bool result;
    int traverse( TreeNode* root )
    {
        int depth = 0;
        if (root)
        {
            int left_depth = traverse( root->left ) + 1;
            int right_depth = traverse( root->right ) + 1;
            depth = max( depth, left_depth );
            depth = max( depth, right_depth );
            result &= (abs( left_depth - right_depth ) <= 1);
        }
        return depth;
    }
    bool isBalanced( TreeNode* root ) {
        result = true;
        traverse( root );                    
        return result;
    }
};