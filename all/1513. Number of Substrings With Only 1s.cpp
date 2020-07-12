class Solution {
public:
	int numSub(string s) {
		int N = s.size();
		int MOD = 1'000'000'007;
		long long result = 0;
		long long count = 0;
		for (char c : s)
		{
			if (c == '1')
				++count;
			else
			{
				result += count * (count + 1) / 2;
				result %= MOD;
				count = 0;
			}
		}
		result += count * (count + 1) / 2;
		result %= MOD;
		return result;
	}
};