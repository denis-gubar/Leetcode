class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		vector<vector<int>> F(n + 1, vector<int>(1 << 10));
		F[0][0] = 1;
		int result = 1;
		for (int i = 0; i < n; ++i)
			for (int mask = 0; mask < (1 << 10); ++mask)
				if (F[i][mask])
					for (int d = 0; d < 10; ++d)
						if ((mask != 0 || d > 0) && ((1 << d) & mask) == 0)
						{
							F[i + 1][mask | (1 << d)] += F[i][mask];
							result += F[i][mask];
						}
		return result;
	}
};