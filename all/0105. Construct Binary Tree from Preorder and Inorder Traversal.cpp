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
    TreeNode* buildTree( const vector<int>& preorder, const vector<int>& inorder ) {
        if (inorder.empty())
            return nullptr;
        int root_value = preorder[0];
        int left_length = distance( inorder.begin(), find( inorder.begin(), inorder.end(), root_value ) );
        TreeNode* root = new TreeNode( root_value );
        root->left = buildTree( vector<int>( preorder.begin() + 1, preorder.begin() + left_length + 1 ), vector<int>( inorder.begin(), inorder.begin() + left_length ) );
        root->right = buildTree( vector<int>( preorder.begin() + left_length + 1, preorder.end() ), vector<int>( inorder.begin() + left_length + 1, inorder.end() ) );
        return root;
    }
};