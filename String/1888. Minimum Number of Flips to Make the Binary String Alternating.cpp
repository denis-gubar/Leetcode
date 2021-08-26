class Solution {
public:
	int minFlips(string s) {
		int N = s.size();
		vector<vector<int>> F(2, vector<int>(2 * N + 1));
		for (int i = 0; i < 2 * N; ++i)
			for (int k = 0; k < 2; ++k)
			{
				int x = s[i % N] % 2 == (i + k) % 2;
				F[k][i + 1] = F[k][i] + x;
			}
		int result = min(F[0][N], F[1][N]);
		for (int i = N; i < 2 * N; ++i)
			for (int k = 0; k < 2; ++k)
				result = min(result, F[k][i + 1] - F[k][i - N + 1]);
		return result;
	}
};