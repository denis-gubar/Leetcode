class Solution {
public:
	int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
		int result = 0;
		vector<vector<int>> R(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n - 1; ++j)
				R[i][preferences[i][j]] = j;
		vector<int>	unhappy(n);
		for (int i = 0; i < n / 2; ++i)
			for (int z = 0; z < 2; ++z)
			{
				int x = pairs[i][0];
				int y = pairs[i][1];
				if (z == 1)
					swap(x, y);
				if (!unhappy[x])
					for (int j = 0; j < n / 2; ++j)
						if (i != j)
							for (int q = 0; q < 2; ++q)
							{
								int v = pairs[j][0];
								int u = pairs[j][1];
								if (q == 1)
									swap(u, v);
								if (R[x][u] < R[x][y] && R[u][x] < R[u][v])
									unhappy[x] = 1;
							}
			}
		return accumulate(unhappy.begin(), unhappy.end(), 0);
	}
};