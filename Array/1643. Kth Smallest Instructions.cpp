int C(int n, int k)
{
	static const int N = 30;
	static bool isCached = false;
	static vector<vector<long long>> cache = vector<vector<long long>>(N + 1, vector<long long>(N + 1));
	if (!isCached)
	{
		for (int i = 0; i <= N; ++i)
			cache[i][0] = cache[i][i] = 1;
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j < i; ++j)
				cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];
	}
	isCached = true;
	return n >= k && k >= 0 && n <= N ? cache[n][k] : 0;
}

class Solution {
public:
	string kthSmallestPath(vector<int>& destination, int k) {
		int v = destination[0], h = destination[1];
		string result;
		while (true)
		{
			if (C(v + h - 1, v) < k)
				result += 'V', k -= C(v + h - 1, v), --v;
			else
				result += 'H', --h;
			if (h == 0 || v == 0)
				break;
		}
		for (int i = 0; i < h; ++i)
			result += 'H';
		for (int i = 0; i < v; ++i)
			result += 'V';
		return result;
	}
};