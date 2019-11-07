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
	bool isSubtree(TreeNode* s, TreeNode* t, bool rootFound = false) {
		if (!t) return rootFound && !s;
		if (!s) return false;
		if (s->val == t->val)
			return (isSubtree(s->left, t->left, true) &&
					isSubtree(s->right, t->right, true)) || 
				!rootFound &&
					(isSubtree(s->left, t, false) || isSubtree(s->right, t, false));
		return !rootFound && (isSubtree(s->left, t, false) ||
			isSubtree(s->right, t, false));
	}
};