class Solution {
public:
	int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
		int INF = 20'000'000;
		for (int i = 0; i < m; ++i)
			if (houses[i])
				for (int j = 0; j < n; ++j)
					if (houses[i] == j + 1)
						cost[i][j] = 0;
					else
						cost[i][j] = INF;
		vector<vector<vector<int>>> F(m + 1, vector<vector<int>>(n + 1, vector<int>(target + 2, 1'000'000'000)));
		F[0][0][0] = 0;
		for(int i = 0; i < m; ++i)
			for(int color = 0; color <= n; ++color)
				for(int t = 0; t <= target; ++t)
					if (F[i][color][t] < INF)
						for (int newColor = 1; newColor <= n; ++newColor)
						{
							int& next = F[i + 1][newColor][t + (i == 0 || color != newColor)];
							next = min(next, F[i][color][t] + cost[i][newColor - 1]);
						}
		int result = INF;
		for (int color = 1; color <= n; ++color)
			result = min(result, F[m][color][target]);
		if (result >= INF)
			result = -1;
		return result;
	}
};