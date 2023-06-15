static long long F[24][401][2][2];
class Solution {
public:
    int const MOD = 1'000'000'007;
	int count(string A, string B, int min_sum, int max_sum) {
		reverse(A.begin(), A.end());
		while (A.size() != B.size())
			A.push_back('0');
		reverse(A.begin(), A.end());
		memset(F, 0, sizeof(F));
		F[0][0][1][1] = 1;
		int N = A.size();
		for (int i = 0; i < N; ++i)
			for (int sum = 0, a = A[i] - '0', b = B[i] - '0'; sum < 300; ++sum)
				for (int isA = 0; isA < 2; ++isA)
					for (int isB = 0; isB < 2; ++isB)
					{
						long long& prevF = F[i][sum][isA][isB];
						if (prevF)
							for (int d = 0; d < 10; ++d)
								if ((!isA || d >= a) && (!isB || d <= b))
								{
									long long& nextF = F[i + 1][sum + d][isA && d == a][isB && d == b];
									nextF += prevF;
									nextF %= MOD;
								}
					}
		long long result = 0;
		for (int sum = min_sum; sum <= max_sum; ++sum)
			for (int isA = 0; isA < 2; ++isA)
				for (int isB = 0; isB < 2; ++isB)
				{
					result += F[N][sum][isA][isB];
					result %= MOD;
				}
		return result;
	}
};
