class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int N = text1.size(), M = text2.size();		
		vector<vector<int>> F(2, vector<int>(M + 1));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (text1[i] == text2[j])
					F[(i + 1) % 2][j + 1] = F[i % 2][j] + 1;
				else
					F[(i + 1) % 2][j + 1] = max(F[(i + 1) % 2][j], F[i % 2][j + 1]);
		return F[N % 2][M];
	}
};