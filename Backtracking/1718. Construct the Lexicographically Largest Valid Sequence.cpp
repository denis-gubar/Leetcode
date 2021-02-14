class Solution {
public:
	bool calc(vector<int>& result, int n, int pos, int mask)
	{
		if (mask + 2 == (1 << (n + 1)))
			return true;
		while (pos < 2 * n && result[pos] != 0)
			++pos;
		if (pos == 2 * n - 1)
			return false;
		for (int x = n; x > 1; --x)
			if (pos + x < 2 * n - 1 && (mask & (1 << x)) == 0 && result[pos + x] == 0)
			{
				result[pos] = result[pos + x] = x;
				bool flag = calc(result, n, pos + 1, mask | (1 << x));
				if (flag)
					return true;
				result[pos] = result[pos + x] = 0;
			}
		if ((mask & (1 << 1)) == 0)
		{
			result[pos] = 1;
			bool flag = calc(result, n, pos + 1, mask | (1 << 1));
			if (flag)
				return true;
			result[pos] = 0;
		}
		return false;
	}
	vector<int> constructDistancedSequence(int n) {
		vector<int>	result(2 * n - 1);
		calc(result, n, 0, 0);
		return result;
	}
};