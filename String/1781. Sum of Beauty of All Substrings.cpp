class Solution {
public:
	int beautySum(string s) {
		int result = 0;
		int N = s.size();
		for (int start = 0; start < N; ++start)
		{
			vector<int>	A(26);
			for (int end = start; end < N; ++end)
			{
				int k = s[end] - 'a';
				++A[k];
				int a = N, b = 0;
				for (int i = 0; i < 26; ++i)
					if (A[i])
						a = min(a, A[i]), b = max(b, A[i]);
				result += b - a;
			}
		}
		return result;
	}
};