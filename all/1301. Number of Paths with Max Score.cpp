class Solution {
public:
	const int MOD = 1000000007;
	vector<int> pathsWithMaxScore(vector<string>& board) {
		vector<int> result{ 0, 0 };
		int N = board.size();
		vector<vector<pair<int, int>>> F(N, vector<pair<int, int>>(N, { -1'000, 0 }));
		queue<int> Q;
		F[N - 1][N - 1] = { 0, 1 };
		vector<int> dx = { -1, 0, -1 };
		vector<int> dy = { 0, -1, -1 };
		for (int x = N - 1; x >= 0; --x)
			for (int y = N - 1; y >= 0; --y)
			{
				int const& sum = F[x][y].first;
				for (int z = 0; z < 3; ++z)
				{
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (nx >= 0 && ny >= 0 && board[nx][ny] != 'X')
					{
						int score = 0;
						if (isdigit(board[nx][ny]))
							score = board[nx][ny] - '0';
						if (F[nx][ny].first < score + sum)
							F[nx][ny] = { score + sum, F[x][y].second };
						else if (F[nx][ny].first == score + sum)
						{
							F[nx][ny].second += F[x][y].second;
							F[nx][ny].second %= MOD;
						}
					}
				}
			}
		if (F[0][0].first >= 0)
			result = { F[0][0].first, F[0][0].second };
		return result;
	}
};