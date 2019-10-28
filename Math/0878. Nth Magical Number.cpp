class Solution {
public:
    template<typename T> T gcd(T a, T b)
    {
        while (a && b) if (a > b) a %= b; else b %= a; return a + b;
    }

    template<typename T> T lcm(T a, T b)
    {
        return a / gcd(a, b) * b;
    }
    static const long long MOD = 1000000007;
	int nthMagicalNumber(int N, int A, int B) {
		int result = 0;
		long long X = lcm(A, B);
		int s = X / A + X / B - 1;
		int k = N / s;
		result = X * k % MOD;
		int delta = 0, a = A, b = B;
		for (int i = k * s; i < N; ++i)
		{
			if (a < b)
			{
				delta = a; a += A;
			}
			else
			{
				delta = b; b += B;
			}
		}
		return (result + delta) % MOD;
	}
};