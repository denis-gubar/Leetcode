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
    pair<int, int> calc(TreeNode* root)
    {
        if (!root) return {0, 0};
        pair<int, int> L = calc(root->left);
        pair<int, int> R = calc(root->right);
        pair<int, int> result = {root->val + L.first + R.first, 1 + L.second + R.second};
        best = max(best, 1.0 * result.first / result.second);
        return result;
    }
	double maximumAverageSubtree(TreeNode* root) {
		best = -1.0;
		calc(root);
		return best;
	}
    double best;
};