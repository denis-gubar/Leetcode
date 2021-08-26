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
    TreeNode* sortedArrayToBST( const vector<int>& nums ) {
        if (nums.empty())
            return nullptr;
        int median = nums.size() / 2;
        TreeNode* root = new TreeNode( nums[median] );
        root->left = sortedArrayToBST( vector<int>( nums.begin(), nums.begin() + median ) );
        root->right = sortedArrayToBST( vector<int>( nums.begin() + median + 1, nums.end() ) );
        return root;
    }
};