class Solution {
public:
	bool check(long long x)
	{
		if (x == 0LL)
			return false;
		string s(to_string(x));
		int N = s.size();
		for (int a = 0, b = N - 1; a < b; ++a, --b)
			if (s[a] != s[b])
				return false;
		return true;
	}
	long long kMirror(int k, int n) {
		long long result = 0;
		vector<long long> P{ 0LL, 1LL };
		while (P.back() < (1LL << 60))
			P.push_back(P.back() * k);
		vector<long long> A;
		vector<int> digits;
		digits.reserve(64);
		for (int length = 1; ; ++length)
			for (long long x = P[length / 2]; x < P[length / 2 + 1]; ++x)
			{
				digits.clear();
				long long y = x;
				while (y > 0)
				{
					digits.push_back(y % k);
					y /= k;
				}
				reverse(digits.begin(), digits.end());
				int D = digits.size();
				long long total = 0;
				for (int i = 0; i < D; ++i)
					total += (P[i + 1] + P[length - i]) * digits[i];
				for (int z = 0, last = (length % 2 == 0) ? 1 : k; z < last; ++z)
				{
					if (check(total))
					{
						result += total;
						A.push_back(total);
						if (A.size() == n)
							return result;
					}
					total += P[length / 2 + 1];
				}
			}
		return -1;
	}
};