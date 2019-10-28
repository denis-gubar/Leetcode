class Solution {
public:
	string shortestCommonSupersequence(string str1, string str2) {
		int N = str1.size(), M = str2.size();
		vector<vector<int>> A(N + 1, vector<int>(M + 1));
		for (int i = 0; i <= M; ++i)
			A[0][i] = i;
		for (int j = 1; j <= N; ++j)
		{
			A[j][0] = j;
			for (int i = 1; i <= M; ++i)
				A[j][i] = min({ str1[j - 1] == str2[i - 1] ? A[j - 1][i - 1] : A[j - 1][i - 1] + 2, A[j][i - 1] + 1, A[j - 1][i] + 1 });
		}
		int j = N, i = M;
		string result;
		while (i + j)
		{
			if (j && i && A[j][i] == A[j - 1][i - 1] && str1[j - 1] == str2[i - 1])
			{
				result += str1[j - 1];
				--i, --j;
			}
			else if (j && A[j][i] == A[j - 1][i] + 1)
			{
				result += str1[j - 1];
				--j;
			}
			else
			{
				result += str2[i - 1];
				--i;
			}
		}
		reverse(result.begin(), result.end());
		return result;
	}
};