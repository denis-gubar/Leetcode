class Solution {
public:
	int atMostNGivenDigitSet(vector<string>& D, int N) {
		vector<int>	digits{ 0 };
		vector<int>	B;
		while (N)
		{
			B.push_back(N % 10);
			N /= 10;
		}
		reverse(B.begin(), B.end());
		N = B.size();
		for (string const& d : D)
			digits.push_back(d[0] - '0');
		vector<vector<vector<int>>> F(N + 1, vector<vector<int>>(2, vector<int>(2)));
		F[0][1][1] = 1;
		for(int i = 0; i < N; ++i)
			for(int isB = 0, b = B[i]; isB < 2; ++isB)
				for(int isZero = 0; isZero < 2; ++isZero)
				if (F[i][isB][isZero])
					for(int d: digits)
						if ((!isB || d <= b) && (!isZero && d != 0 || isZero))
						{
							int& next = F[i + 1][isB && d == b][isZero && d == 0];
							next += F[i][isB][isZero];
						}
		return F[N][1][0] + F[N][0][0];
	}
};