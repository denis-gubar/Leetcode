class Solution {
public:
	int minCost(string s, vector<int>& cost) {
		int result = 1'000'000'001;
		int N = s.size();
		vector<vector<int>> F(27, vector<int>(N + 1, 1'000'000'001));
		F[26][0] = 0;
		for (int i = 0; i < N; ++i)
			for (int c = 0, x = s[i] - 'a'; c <= 26; ++c)
            {
				if (c != x)
					F[x][i + 1] = min(F[x][i + 1], F[c][i]);
                F[c][i + 1] = min(F[c][i + 1], F[c][i] + cost[i]);
            }
		for (int c = 0; c < 27; ++c)
			result = min(result, F[c][N]);
		return result;
	}
};