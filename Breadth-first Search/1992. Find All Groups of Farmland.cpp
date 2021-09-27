class Solution {
public:
	vector<vector<int>> findFarmland(vector<vector<int>>& land) {
		vector<int> dx{ 0, -1, 0, 1 };
		vector<int> dy{ -1, 0, 1, 0 };
		int N = land.size(), M = land[0].size();
		vector<vector<int>> result;
		for(int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (land[i][j] == 1)
				{
					queue<int> Q;
					result.push_back({ i, j, i, j });
					Q.push(i); Q.push(j);
					land[i][j] = 2;
					while (!Q.empty())
					{
						int x = Q.front(); Q.pop();
						int y = Q.front(); Q.pop();
						result.back()[0] = min(result.back()[0], x);
						result.back()[1] = min(result.back()[1], y);
						result.back()[2] = max(result.back()[2], x);
						result.back()[3] = max(result.back()[3], y);
						for (int z = 0; z < 4; ++z)
						{
							int nx = x + dx[z];
							int ny = y + dy[z];
							if (nx >= 0 && nx < N && ny >= 0 && ny < M && land[nx][ny] == 1)
							{
								Q.push(nx); Q.push(ny);
								land[nx][ny] = 2;
							}
						}
					}
				}
		return result;
	}
};