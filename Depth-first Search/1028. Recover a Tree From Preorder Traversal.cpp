class Solution {
public:
	TreeNode* recoverFromPreorder(string S) {
		TreeNode* root = nullptr;
		S = '#' + S + '#';
		int val = 0, level = 0;
		stack<TreeNode*> A;
		for (int i = 1; i < S.size(); ++i)
		{
			if (S[i] == '#' || S[i] == '-')
			{
				//process val
				if (S[i] == '#' || S[i - 1] != '-')
				{
					if (!level)
					{
						root = new TreeNode(val);
						A.push(root);
					}
					else
					{
						while (A.size() > level)
							A.pop();
						TreeNode* node = new TreeNode(val);
						if (A.top()->left)
							A.top()->right = node;
						else
							A.top()->left = node;
						A.push(node);
					}
				}
				if (S[i] == '-')
				{
					if (S[i - 1] == '-')
						++level;
					else
						level = 1;
				}
			}
			else
			{
				if (S[i - 1] == '#' || S[i - 1] == '-')
					val = S[i] - '0';
				else
					val = val * 10 + S[i] - '0';
			}
		}
		return root;
	}
};