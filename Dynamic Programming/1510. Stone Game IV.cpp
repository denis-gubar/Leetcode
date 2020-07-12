class Solution {
public:
	int calc(int n, vector<int>& F)
	{
		if (!F[n])
		{
			F[n] = 2;
			for (int x = 1; x * x <= n; ++x)
				F[n] = min(F[n], 3 - calc(n - x * x, F));
		}
		return F[n];
	}
	bool winnerSquareGame(int n) {
		vector<int> F(n + 1);
		F[0] = 2;
		return calc(n, F) == 1;
	}
};