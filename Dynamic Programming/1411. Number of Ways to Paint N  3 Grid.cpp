class Solution {
public:
	static const int MOD = 1000000007;
	enum Color {Red = 1, Yellow = 2, Green = 4};
	int x(Color a, Color b, Color c)
	{
		return (a << 6) | (b << 3) | c;
	}
	int numOfWays(int n) {
		vector<int> tiles{
			x(Red, Yellow, Red),      //00
			x(Red, Yellow, Green),	  //01
			x(Red, Green, Red),		  //02
			x(Red, Green, Yellow),	  //03
			x(Yellow, Red, Yellow),	  //04
			x(Yellow, Red, Green),	  //05
			x(Yellow, Green, Red),	  //06
			x(Yellow, Green, Yellow), //07
			x(Green, Red, Yellow),	  //08
			x(Green, Red, Green),	  //09
			x(Green, Yellow, Red),	  //10
			x(Green, Yellow, Green),  //11
		};
		vector<vector<int>> next(12);
		for (int i = 0; i < 12; ++i)
			for (int j = 0; j < 12; ++j)
				if ((tiles[i] & tiles[j]) == 0)
					next[i].push_back(j);
		vector<vector<long long>> F(n, vector<long long>(12));
		for (int j = 0; j < 12; ++j)
			F[0][j] = 1;
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < 12; ++j)
				for (int N : next[j])
				{
					F[i][N] += F[i - 1][j];
					F[i][N] %= MOD;
				}
		long long result = accumulate(F.back().begin(), F.back().end(), 0LL);
		return result % MOD;
	}
};