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
	static const int MOD = 1000000007;
	int calc(TreeNode* root, vector<int>& sum)
	{
		if (!root) return 0;
		int result = root->val + calc(root->left, sum) + calc(root->right, sum);
		sum.push_back(result);
		return result;
	}
	int maxProduct(TreeNode* root) {
		vector<int> sum;
		calc(root, sum);
        long long totalSum = sum.back();
        sum.pop_back();
		vector<long long> A;
		for (int s : sum)
			A.push_back(1LL * s * (totalSum - s));
		return (*max_element(A.begin(), A.end())) % MOD;
	}
};