class Solution {
public:
	bool sumGame(string num) {
		int a = 0, b = 0, N = num.size();
		int L = 0, R = 0;
		for (int i = 0; i < N / 2; ++i)
			if (num[i] != '?')
				a += num[i] - '0';
			else
				++L;
		for (int i = N / 2; i < N; ++i)
			if (num[i] != '?')
				b += num[i] - '0';
			else
				++R;
		if (L == R)
		    return a != b;
		if ((L + R) % 2 == 1)
			return true;
		if (L > R)
		{
			swap(L, R);
			swap(a, b);
		}
		return (R - L) * 9 / 2 != a - b;
	}
};