class Solution {
public:
	int minKnightMoves(int x, int y) {
		int result = 0;
		x = abs(x) + 1, y = abs(y) + 1;
		vector<vector<int>> grid(302, vector<int>(302, 10'000));
		queue<int> Q;
		Q.push(1), Q.push(1);
		grid[1][1] = 0;
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
						if (na >= 0 && na <= 301 && nb >= 0 && nb <= 301 && grid[na][nb] > s + 1)
						{
							grid[na][nb] = s + 1;
							Q.push(na); Q.push(nb);
						}
					}
		}
		return grid[x][y];
	}
};
