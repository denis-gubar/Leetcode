class Solution {
public:
	int concatenatedBinary(int n) {
		long long result = 0;
		int const MOD = 1'000'000'007;
		for (int x = 1; x <= n; ++x)
		{
			int z = x;
            int k = 0;
			while (z)
			{
				z >>= 1;
                ++k;
			}
            result <<= k;
            result += x;
            result %= MOD;
		}
		return result;
	}
};