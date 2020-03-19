class Solution {
public:
	const int MOD = 1000000007;
	int numWays(int steps, int arrLen) {
		arrLen = min(arrLen, steps + 1);
		vector<vector<long long>> F(2, vector<long long>(arrLen));
		F[0][0] = 1;
		for (int k = 0; k < steps; ++k)
			for (int j = 0; j < arrLen; ++j)
			{
				F[(k + 1) % 2][j] = F[k % 2][j] + 
                    (j + 1 < arrLen ? F[k % 2][j + 1] : 0) +
                    (j > 0 ? F[k % 2][j - 1] : 0);
				F[(k + 1) % 2][j] %= MOD;
			}
		return F[steps % 2][0];
	}
};