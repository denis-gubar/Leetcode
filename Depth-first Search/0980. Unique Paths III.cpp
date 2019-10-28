class Solution {
public:
	int uniquePathsIII(vector<vector<int>>& grid) {
		int N = grid.size(), M = grid[0].size();
		vector<bool> state(N * M), endState(N * M, true);
		int sx = 0, sy = 0, ex = 0, ey = 0;
		map<pair<vector<bool>, int>, int> result;
		set<pair<vector<bool>, int>> visited;
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, -1, 0, 1 };
		for (int i = 0, key = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				if (grid[i][j] == -1)
					state[key] = true;
				else if (grid[i][j] == 1)
					sx = i, sy = j, state[key] = true;
				else if (grid[i][j] == 2)
					ex = i, ey = j;
				++key;
			}
		result[make_pair(state, sx * M + sy)] = 1;
		visited.insert(make_pair(state, sx * M + sy));
		queue<vector<bool>> Q;
		Q.push(state);
		queue<int> q;
		q.push(sx); q.push(sy);
		while (!Q.empty())
		{
			state = Q.front(); Q.pop();
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			if (state != endState)
			{
				int count = result[make_pair(state, x * M + y)];
				for (int z = 0; z < 4; ++z)
				{
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M && !state[nx * M + ny] && grid[nx][ny] % 2 == 0)
					{
						vector<bool> newState(state);
						newState[nx * M + ny] = true;
						result[make_pair(newState, nx * M + ny)] += count;
						if (visited.find(make_pair(newState, nx * M + ny)) == visited.end())
						{
							visited.insert(make_pair(newState, nx * M + ny));
							Q.push(newState);
							q.push(nx); q.push(ny);
						}
					}
				}
			}
		}
		return result[make_pair(endState, ex * M + ey)];
	}
};