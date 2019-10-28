class Solution {
public:
	int minKnightMoves(int x, int y) {
		int result = 0;
		x = abs(x), y = abs(y);
		vector<vector<int>> grid(301, vector<int>(301, 10'000));
		queue<int> Q;
		Q.push(0), Q.push(0);
		grid[0][0] = 0;
		while (!Q.empty())
		{
			int a = Q.front(); Q.pop();
			int b = Q.front(); Q.pop();
			int s = grid[a][b];
			if (a == x && b == y)
				break;
			for(int dx = -2; dx <= 2; ++dx)
				for(int dy = -2; dy <= 2; ++dy)
					if (abs(dx) + abs(dy) == 3)
					{
						int na = a + dx, nb = b + dy;
						if (na >= 0 && na <= 300 && nb >= 0 && nb <= 300 && grid[na][nb] > s + 1)
						{
							grid[na][nb] = s + 1;
							Q.push(na); Q.push(nb);
						}
					}
		}
		return grid[x][y];
	}
};
