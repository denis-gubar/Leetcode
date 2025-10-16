class Solution {
public:
	int countPalindromicSubsequence(string s) {
		int result = 0;
		int N = s.size();
		vector<vector<int>> A(26);
		for (int i = 0; i < N; ++i)
			A[s[i] - 'a'].push_back(i);
		for(int a = 0; a < 26; ++a)
			if (A[a].size() > 1)
			{
				int start = A[a][0];
				int end = A[a].back();
				for (int b = 0; b < 26; ++b)
				{
					auto it = upper_bound(A[b].begin(), A[b].end(), start);
					if (it != A[b].end() && *it < end)
						++result;
				}
			}
		return result;
	}
};