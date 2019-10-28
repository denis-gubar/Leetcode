class Solution {
public:
	int fib(int N) {
		vector<int> F(31);
		F[1] = 1;
		for (int n = 2; n < 31; ++n)
			F[n] = F[n - 1] + F[n - 2];
		return F[N];
	}
};