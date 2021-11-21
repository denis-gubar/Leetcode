class Solution {
public:
	int minimizedMaximum(int n, vector<int>& quantities) {
		sort(quantities.begin(), quantities.end());
		int a = 0, b = quantities.back();
		auto calc = [n, &quantities](int m)
		{
			long long total = 0;
			for (int q : quantities)
				total += (q + m - 1) / m;
			return total <= n;
		};
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (calc(m))
				b = m;
			else
				a = m;
		}
		return b;
	}
};