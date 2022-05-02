class Solution {
public:
	int numWays(int n, int k) {
		vector<vector<int>> M(n + 1, vector<int>(2));
		M[1][0] = k;
		for (int i = 2; i <= n; ++i)
		{
			M[i][0] = (M[i - 1][0] + M[i - 1][1]) * (k - 1);
			M[i][1] = M[i - 1][0];
		}
		return M[n][0] + M[n][1];
	}
};