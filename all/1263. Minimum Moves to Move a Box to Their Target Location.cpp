class Solution {
public:
	vector<int> dx{ -1, 0, 1, 0 };
	vector<int> dy{ 0, 1, 0, -1 };
	int N, M;
	vector<int> calcPositions(vector<vector<int>> B, int sx, int sy, int bx, int by)
	{
		queue<int> q;
		vector<int> result;
		q.push(sx); q.push(sy);
		B[sx][sy] = 1; B[bx][by] = 2;
		while (!q.empty())
		{
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			for (int z = 0; z < 4; ++z)
				if (x + dx[z] == bx && y + dy[z] == by)
					result.push_back(z);
			for (int z = 0; z < 4; ++z)
			{
				int nx = x + dx[z], ny = y + dy[z];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && B[nx][ny] == 0)
				{
					q.push(nx); q.push(ny);
					B[nx][ny] = 1;
				}
			}
		}
		return result;
	}
	int minPushBox(vector<vector<char>>& grid) {
		int result = 0;
		N = grid.size(), M = grid[0].size();
		vector<vector<int>> A(N, vector<int>(M));
		int bx = 0, by = 0, sx = 0, sy = 0, tx = 0, ty = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (grid[i][j] == 'B')
					bx = i, by = j, A[i][j] = 0;
				else if (grid[i][j] == 'S')
					sx = i, sy = j;
				else if (grid[i][j] == 'T')
					tx = i, ty = j;
				else if (grid[i][j] == '#')
					A[i][j] = 1;
		queue<int> q;
		set<vector<int>> visited;
		for (int pos : calcPositions(A, sx, sy, bx, by))
			q.push(bx), q.push(by), q.push(pos), q.push(0), visited.insert({bx, by, pos});
		while (!q.empty())
		{
			int bx = q.front(); q.pop();
			int by = q.front(); q.pop();
			int pos = q.front(); q.pop();
			int length = q.front(); q.pop();
			if (bx == tx && by == ty)
				return length;
			int sx = bx + dx[(pos + 2) % 4];
			int sy = by + dy[(pos + 2) % 4];
			int nbx = bx + dx[pos];
			int nby = by + dy[pos];
			if (nbx >= 0 && nbx < N && nby >= 0 && nby < M && A[nbx][nby] == 0)
				for(int pos: calcPositions(A, bx, by, nbx, nby))
					if (visited.find({ nbx, nby, pos }) == visited.end())
					{
						visited.insert({ nbx, nby, pos });
						q.push(nbx); q.push(nby); q.push(pos); q.push(length + 1);
					}
		}
		return -1;
	}
};