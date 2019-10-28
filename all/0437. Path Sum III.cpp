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
    int traverse( TreeNode* root, int target )
    {
        int result = calc( root, 0, target );
        if (root->left)
            result += traverse( root->left, target );
        if (root->right)
            result += traverse( root->right, target );
        return result;
    }
    int calc( TreeNode* root, int sum, int target )
    {
        int result = 0;
        if (sum + root->val == target)
            ++result;
        if (root->left)
            result += calc( root->left, sum + root->val, target );
        if (root->right)
            result += calc( root->right, sum + root->val, target );
        return result;
    }
    int pathSum( TreeNode* root, int sum ) {
        if (!root)
            return 0;
        return traverse( root, sum );
    }
};;