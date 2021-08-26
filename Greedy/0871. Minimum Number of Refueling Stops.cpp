class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		int N = stations.size();
		int delta = target;
		if (N)
			delta -= stations.back()[0];
		vector<vector<long long>> M(N + 1, vector<long long>(N + 1, -1));
		M[0][0] = startFuel;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (M[i - 1][j] >= 0 && stations[i - 1][0] - (i == 1 ? 0 : stations[i - 2][0]) <= M[i - 1][j])
					M[i][j] = max(M[i][j], M[i - 1][j] - (stations[i - 1][0] - (i == 1 ? 0 : stations[i - 2][0])));
				if (M[i][j] >= 0)
					M[i][j + 1] = max(M[i][j + 1], M[i][j] + stations[i - 1][1]);
			}
		}
		for (int j = 0; j <= N; ++j)
			if (M[N][j] >= delta)
				return j;
		return -1;
	}
};