class Solution {
public:
	int calc(vector<int> const& piles, int start = 0, int M = 1)
	{
		while (!F[start][M])
		{
			if (piles.size() - start <= 2 * M)
			{
				F[start][M] = accumulate(piles.begin() + start, piles.end(), 0);
				break;
			}
			int result = 0;
			for (int X = 1; X <= 2 * M; ++X)
				result = max(result, S[start] - calc(piles, start + X, max(M, X)));
			F[start][M] = result;
			break;
		}
		return F[start][M];
	}
	int stoneGameII(vector<int>& piles) {
		F = vector<vector<int>>(piles.size(), vector<int>(2 * piles.size() + 1));
		S = vector<int>(piles.size());
		S.back() = piles.back();
		for (int i = S.size() - 2; i >= 0; --i)
			S[i] = S[i + 1] + piles[i];
		return calc(piles);
	}
	vector<vector<int>> F;
	vector<int> S;
};