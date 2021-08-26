template <int base>
struct HashString
{
	const int MOD = 1'000'000'007;
	HashString(const string& s) : data(s), N(s.size()), prefixes(vector<int>(N + 1)), power(prefixes)
	{
		power[0] = 1;
		for (int i = 1; i <= N; ++i)
		{
			power[i] = 1LL * power[i - 1] * base % MOD;
			prefixes[i] = (1LL * prefixes[i - 1] * base + hash(s[i - 1])) % MOD;
		}
	}
	static int hash(char c)
	{
		return c - 'a' + 1;
	}
	int hash(int start, int length) const
	{
		return (prefixes[start + length] - 1LL * prefixes[start] * power[length] % MOD + MOD) % MOD;
	}
	int N;
	vector<int> prefixes;
	vector<int> power;
	string data;
};

class Solution {
public:
	string longestDupSubstring(string S) {
		string result = "";
		HashString<29> H1(S);
		HashString<31> H2(S);
		int N = S.size(), a = 0, b = N;
		while (a + 1 < b)
		{
			int length = (a + b) / 2;
			map<pair<int, int>, int> X;
			bool duplicated = false;
			for (int start = 0; start + length <= N; ++start)
			{
				pair<int, int> current{ H1.hash(start, length), H2.hash(start, length) };
				if (X.find(current) == X.end())
					X[current] = start;
				else
				{
					result = S.substr(start, length);
					duplicated = true;
					break;
				}
			}
			if (duplicated)
				a = length;
			else
				b = length;
		}
		return result;
	}
};