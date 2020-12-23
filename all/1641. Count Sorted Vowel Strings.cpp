int C(int n, int k)
{
	static const int N = 55;
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
	int countVowelStrings(int n) {
		return C(n + 4, n);
	}
};