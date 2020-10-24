class Solution {
public:
	int numWays(string s) {
		int N = s.size();
		int MOD = 1'000'000'007;
		int total = count(s.begin(), s.end(), '1');
		if (total % 3 != 0)
			return 0;
		long long result = 0;
		if (total == 0)
		{
			for (int i = 1; i + 1 < N; ++i)
				result += N - i - 1;
			return result % MOD;
		}
		int current = 0;
		long long a = 0, b = 0;
		for (char c : s)
		{
			if (c == '1')
				++current;
			if (current == total / 3)
				++a;
			if (current == 2 * total / 3)
				++b;
		}
		result = a * b;
		return result % MOD;
	}
};