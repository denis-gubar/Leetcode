class Solution {
public:
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		int N = isWater.size(), M = isWater[0].size();
		int const INF = 1 << 20;
		vector<vector<int>> result(N, vector<int>(M, INF));
		vector<pair<int, int>> A;
		vector<int> dx{ 0, 1, 0, -1 };
		vector<int> dy{ 1, 0, -1, 0 };
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (isWater[i][j])
				{
					A.emplace_back(i, j);
					result[i][j] = 0;
				}
		int height = 1;
		while (!A.empty())
		{
			vector<pair<int, int>> NA;
			for (auto [x, y] : A)
			{
				for (int z = 0; z < 4; ++z)
				{
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (nx < N && nx >= 0 && ny < M && ny >= 0 && result[nx][ny] == INF)
					{
						result[nx][ny] = height;
						NA.emplace_back(nx, ny);
					}
				}
			}
			++height;
			A = move(NA);
		}
		return result;
	}
};