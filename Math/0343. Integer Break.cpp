class Solution {
public:
	int integerBreak(int n) {
		vector<int>	F(59);
		F[2] = 1;
		for (int x = 3; x < 59; ++x)
			for (int a = 1; a + a <= x; ++a)
				F[x] = max(F[x], max(F[a], a) * max(F[x - a], x - a));
		return F[n];
	}
};