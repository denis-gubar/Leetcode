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
	TreeNode* calc(vector<int>::iterator first, vector<int>::iterator last)
	{
		if (first == last) return nullptr;
		TreeNode* result = new TreeNode(*first);
		++first;
		auto it = find_if(first, last, [result](int x)
			{
				return x > result->val;
			});
		result->left = calc(first, it);
		result->right = calc(it, last);
		return result;
	}
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		return calc(preorder.begin(), preorder.end());
	}
};