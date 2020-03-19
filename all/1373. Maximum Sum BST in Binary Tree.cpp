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
	vector<int>  isValidBST(TreeNode* root) {
		if (!root)	return {1};
		vector<int> L = isValidBST(root->left);
		vector<int> R = isValidBST(root->right);
		bool result = L.size() < 3 || L[2] < root->val;
		result &= R.size() < 3 || R[1] > root->val;
        result &= L[0];
        result &= R[0];
		int a = root->val, b = root->val;
        cout << root->val << ' ' << result << '\n';
		if (!result) return { 0 };
		if (L.size() == 3)
			a = L[1];
		if (R.size() == 3)
			b = R[2];
		isBST[root] = result;
		return { 1, a, b };
	}
	int sum(TreeNode* root)
	{
		if (!root) return 0;
		int result = root->val + sum(root->left) + sum(root->right);
		if (isBST[root])
        {
			bestSum = max(bestSum, result);
        }
		return result;
	}
	int maxSumBST(TreeNode* root) {
		if (!root) return 0;
		bestSum = 0;
		isBST.clear();
		isValidBST(root);
        sum(root);
        return bestSum;
	}
	map<TreeNode*, bool> isBST;
	int bestSum;
};