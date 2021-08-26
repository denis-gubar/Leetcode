class Solution {
public:
	int countHomogenous(string s) {
		int MOD = 1'000'000'007;
		char prev = '$';
		long long x = 0;
		long long result = 0;
		for (char c : s)
		{
			if (c == prev)
				++x;
			else
			{
				result += x * (x + 1) / 2;
				result %= MOD;
				x = 1;
				prev = c;
			}
		}
		result += x * (x + 1) / 2;
		result %= MOD;
		return result;
	}
};