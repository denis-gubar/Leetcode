class Solution {
public:
	bool isPalindrome(long long x)
	{
		string s = to_string(x);
		for (int a = 0, b = s.size() - 1; a < b; ++a, --b)
			if (s[a] != s[b])
				return false;
		return true;
	}
	int superpalindromesInRange(string left, string right) {
		vector<long long> P{ 1, 4, 9 };
		for (int k = 3; ; ++k)
			if (k % 3)
			{
				long long x = 0;
				int n = k;
				while (n)
				{
					x = x * 10 + n % 3;
					n /= 3;
				}
				if (x > 1'000'000'000)
					break;
				if (isPalindrome(x) && isPalindrome(x * x))
					P.push_back(x * x);
			}
		long long L = stoll(left), R = stoll(right);
		return lower_bound(P.begin(), P.end(), R + 1) - lower_bound(P.begin(), P.end(), L);
	}
};