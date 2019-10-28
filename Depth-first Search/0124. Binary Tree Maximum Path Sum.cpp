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
    int sum( TreeNode* root )
    {
        int best_sum = 0;
        if (root)
        {
            best_sum = root->val;
            int left = sum( root->left );
            int right = sum( root->right );
            vector<int> all_sums;
            all_sums.push_back( result );
            all_sums.push_back( root->val );
            if (root->left)
            {
                all_sums.push_back( left );
                all_sums.push_back( root->val + left );
            }
            if (root->right)
            {
                all_sums.push_back( right );
                all_sums.push_back( root->val + right );
            }
            if (root->left && root->right)
                all_sums.push_back( root->val + left + right );
            result = *max_element( all_sums.begin(), all_sums.end() );
            best_sum = max( best_sum, max( best_sum + left, best_sum + right ) );            
        }
        return best_sum;
    }
    int maxPathSum( TreeNode* root ) {
        result = INT_MIN;
        sum( root );
        return result;
    }
};