class Solution {
public:
	bool stoneGame(vector<int>& piles) {
		int N = piles.size();
		vector<vector<int>> M(N, vector<int>(N));
		for (int i = 0; i < N; ++i)
			M[0][i] = piles[i];
		for(int k = 1; k < N; ++k)
			for (int start = 0; start + k < N; ++start)
			{
				M[k][start] = max(abs(M[k - 1][start] - piles[start + k]),
					abs(M[k - 1][start + 1] - piles[start]));
			}
		return M[N - 2][0] < piles[N - 1] || M[N - 2][N - 1] < piles[0];
	}
};