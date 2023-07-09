class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int result = 0;
		vector<vector<int>> F(2, vector<int>(200'001, -1));
		const int MOD = 1'000'000'007;
		F[0][0] = 1;
		for(int i = 0; i < high; ++i)
			for(int k = 0; k < 2; ++k)
				if (F[k][i] >= 0)
				{
					if (F[0][i + zero] < 0)
						F[0][i + zero] = F[k][i];
					else
					{
						F[0][i + zero] += F[k][i];
						F[0][i + zero] %= MOD;
					}
					if (F[1][i + one] < 0)
						F[1][i + one] = F[k][i];
					else
					{
						F[1][i + one] += F[k][i];
						F[1][i + one] %= MOD;
					}
				}
		for(int i = low; i <= high; ++i)
			for(int k = 0; k < 2; ++k)
				if (F[k][i] > 0)
				{
					result += F[k][i];
					result %= MOD;
				}
		return result;
    }
};