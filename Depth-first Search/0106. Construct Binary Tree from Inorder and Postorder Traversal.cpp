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
    TreeNode* buildTree( const vector<int>& inorder, const vector<int>& postorder ) {
        if (inorder.empty())
            return nullptr;
        int root_value = postorder.back();
        int left_length = distance( inorder.begin(), find( inorder.begin(), inorder.end(), root_value ) );
        TreeNode* root = new TreeNode( root_value );
        root->left = buildTree( vector<int>( inorder.begin(), inorder.begin() + left_length ), vector<int>( postorder.begin(), postorder.begin() + left_length ) );
        root->right = buildTree( vector<int>( inorder.begin() + left_length + 1, inorder.end() ), vector<int>( postorder.begin() + left_length, postorder.end() - 1 ));
        return root;
    }
};