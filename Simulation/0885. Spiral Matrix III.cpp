class Solution {
public:
	vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
		vector<vector<int>> result;
		vector<int> dx{ 0, 1, 0, -1 };
		vector<int> dy{ 1, 0, -1, 0 };
		int x = r0, y = c0, d = 0, K = 1;
		result.push_back({x, y});
		for (int t = 0, k = 0; result.size() < R * C; ++t)
		{
			x += dx[d]; y += dy[d];
			if (x >= 0 && x < R && y >= 0 && y < C)
				result.push_back({ x, y });
			++t; ++k;
			if (k % K == 0)
				d = (d + 1) % 4;
			if (k == 2 * K)
			{
				++K; k = 0;
			}
		}		
		return result;
	}
};
