class Solution {
public:
	int shift(int a, int b)
	{
        if (a > b)
            b += 26;
		return (b - a) % 26;
	}
	bool canConvertString(string s, string t, int k) {
		if (s.size() != t.size()) return false;
		int N = s.size();
		vector<int>	A(26);
		for (int i = 0; i < N; ++i)
			++A[shift(s[i] - 'a', t[i] - 'a')];
		long long high = 0;
		for (int i = 1; i < 26; ++i)
			if (A[i])
				high = max<long long>(high, (A[i] - 1) * 26LL + i);
		return high <= k;
	}
};