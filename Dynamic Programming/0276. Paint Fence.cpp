class Solution {
public:
	int numWays(int n, int k) {
        if (n * k == 0)
            return 0;
		if (n == 1)
			return k;
		vector<vector<int>> M(n + 1, vector<int>(2));
		M[2][0] = k * (k - 1);
		M[2][1] = k;
		for (int i = 3; i <= n; ++i)
		{
			M[i][0] = (M[i - 1][0] + M[i - 1][1]) * (k - 1);
			M[i][1] = M[i - 1][0];
		}
		return M[n][0] + M[n][1];
	}
};