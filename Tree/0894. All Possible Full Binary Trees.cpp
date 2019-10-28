class Solution {
public:
	vector<TreeNode*> allPossibleFBT(int N) {
		vector<TreeNode*> result;
		if (N % 2)
		{
			for (int x = 0; x < (1 << N); ++x)
			{
				int oneCount = 0, zeroCount = 0;
				bool isCorrect = true;
				vector<int> current(N);
				for (int k = 0; k < N; ++k)
				{
					if (x & (1 << k))
						++oneCount, current[k] = 1;
					else
						++zeroCount;
					if (oneCount > N / 2 || !(oneCount >= zeroCount || oneCount + 1 == zeroCount && k == N - 1))
					{
						isCorrect = false;
						break;
					}
				}
				if (oneCount == N / 2 && isCorrect)
				{
					TreeNode* root = new TreeNode(0);
					queue<TreeNode*> Q;
					Q.push(root);
					for (int i = 0; i + 1 < N; ++i)
					{
						TreeNode* node = Q.front(); Q.pop();
						if (current[i])
						{
							node->left = new TreeNode(0);
							Q.push(node->left);
							node->right = new TreeNode(0);
							Q.push(node->right);
						}
					}
					result.push_back(root);
				}
			}
		}
		return result;
	}
};