class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> F(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));
        for (int length = 0; length <= n; ++length)
		    for (int i = 0; i + length <= n; ++i)			
			{
				int j = i + length;
				if (i == j)
					F[i][j] = 0;
				else if (i + 1 == j)
					F[i][j] = i;
				else
					for (int k = i + 1; k < j; ++k)
						F[i][j] = min(F[i][j], max(F[i][k - 1] + k, F[k + 1][j] + k));
			}
		return F[1][n];
	}
};