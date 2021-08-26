class Solution {
public:
	int longestValidParentheses(string s) {
		int result = 0;
		int N = s.size();
		vector<int> A;
		int level = 0;
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == '(')
			{
				++level;
				if (level > A.size())
					A.push_back(i);
			}
			else
			{
				if (level > 0)
					--level;
				else
					A.clear();
				if (level < A.size())
				{
					result = max(result, i - A[level] + 1);
					if (level + 1 < A.size())
						A.pop_back();
				}
				else if (!A.empty())
					A.pop_back();
			}
		}
		return result;
	}
};