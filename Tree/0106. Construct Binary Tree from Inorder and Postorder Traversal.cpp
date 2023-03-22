/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	using Iterator = vector<int>::iterator;
    unordered_map<int, int> M;
    Iterator begin;
	TreeNode* calc(Iterator in_first, Iterator in_last, Iterator post_first, Iterator post_last)
	{
		if (in_first == in_last) return nullptr;
		--post_last;
		TreeNode* root = new TreeNode(*post_last);
		auto in_middle = begin + M[*post_last];
		auto delta = M[*post_last] - M[*in_first];
		root->left = calc(in_first, in_middle, post_first, post_first + delta);
		root->right = calc(in_middle + 1, in_last, post_first + delta, post_last);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int N = inorder.size();
        begin = inorder.begin();
        for(int i = 0; i < N; ++i)
            M[inorder[i]] = i;
		return calc(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}
};