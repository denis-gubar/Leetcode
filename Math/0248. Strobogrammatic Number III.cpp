class Solution {
public:
	void calc(int pos, string& number, int n)
	{
		if (pos == number.size())
		{
			if (n % 2 == 1 && M[number.back()] != number.back())
				return;
			string current(number);
			for (int i = n / 2 - 1; i >= 0; --i)
				current += M[number[i]];
            long long x = atoll(current.c_str());
			if (x >= L && x <= H)
                ++result;
			return;
		}
		if (pos > 0 || n == 1)
		{
			number[pos] = good[0];
			calc(pos + 1, number, n);
		}
		for (int x = 1; x < 5; ++x)
		{
			number[pos] = good[x];
			calc(pos + 1, number, n);
		}
	}
	int strobogrammaticInRange(string low, string high) {
		result = 0;
		L = atoll(low.c_str()), H = atoll(high.c_str());
		M = vector<int>(128);
		for (int i = 0; i < 5; ++i)
			M[good[i]] = rotated[i];
		for (int n = low.size(); n <= high.size(); ++n)
		{
			string number((n + 1) / 2, '0');
			calc(0, number, n);
		}
		return result;
	}
	long long L, H;
	int result;
	vector<int> M;
	const string good{ "01689" };
	const string rotated{ "01986" };
};