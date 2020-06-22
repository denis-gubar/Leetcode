class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int N = board.size();
		if (N == 0) return;
		int M = board[0].size();
		vector<int>	dx{ 0, -1, 0, 1 };
		vector<int>	dy{ -1, 0, 1, 0 };
		auto checkInside = [N, M](int i, int j)
		{
			return i > 0 && i + 1 < N && j > 0 && j + 1 < M;
		};
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (board[i][j] == 'O')
				{
					queue<int> Q;
					Q.push(i); Q.push(j);
					board[i][j] = '?';					
					vector<pair<int, int>> P;
					P.emplace_back(i, j);
					while (!Q.empty())
					{
						int x = Q.front(); Q.pop();
						int y = Q.front(); Q.pop();
						for (int z = 0; z < 4; ++z)
						{
							int nx = x + dx[z];
							int ny = y + dy[z];
							if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
								board[nx][ny] == 'O')
							{
								Q.push(nx); Q.push(ny);
                                P.emplace_back(nx, ny);
								board[nx][ny] = '?';
							}
						}
					}
					bool isInside = true;
					if (isInside)
						for (pair<int, int> p : P)
							if (!checkInside(p.first, p.second))
							{
								isInside = false;
								break;
							};
					if (isInside)
						for (pair<int, int> p : P)
							board[p.first][p.second] = 'X';
				}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (board[i][j] == '?')
					board[i][j] = 'O';
	}
};