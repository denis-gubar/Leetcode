class Solution {
public:
	int F[11][1024][2][2][2];
	int numDupDigitsAtMostN(int N) {
		memset(F, 0, sizeof(F));
		F[0][0][0][1][1] = 1;
		string B{ to_string(N) };
		N = B.size();
		for (int i = 0; i < N; ++i)
			for (int mask = 0, b = B[i] - '0'; mask < 1024; ++mask)
				for (int isRepeated = 0; isRepeated < 2; ++isRepeated)
					for (int isB = 0; isB < 2; ++isB)
						for (int isZero = 0; isZero < 2; ++isZero)
							if (F[i][mask][isRepeated][isB][isZero])
							{
								for (int d = 0; d < 10; ++d)
									if (!isB || d <= b)
									{
										auto const& prev = F[i][mask][isRepeated][isB][isZero];
										if (isZero && d == 0)
											F[i + 1][mask][0][isB && d == b][isZero] = prev;
										else
										{
											auto& next = F[i + 1][mask | (1 << d)][isRepeated || (((1 << d) & mask) != 0)][isB && d == b][0];
											next += prev;
										}
									}
							}
		int result = 0;
        for (int mask = 0; mask < 1024; ++mask)
            for (int isB = 0; isB < 2; ++isB)
                result += F[N][mask][1][isB][0];
		return result;
	}
};