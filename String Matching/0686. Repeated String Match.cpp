class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		int N = A.size(), M = B.size();
		auto check = [&A, &B](int k)
		{
			string x;
			for (int i = 0; i < k; ++i)
				x += A;
			return x.find(B) != string::npos;
		};
		int a = 0, b = max(2, (2 * M + N - 1) / N);
		if (!check(b))
			return -1;
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (check(m))
				b = m;
			else
				a = m;
		}
		return b;
	}
};