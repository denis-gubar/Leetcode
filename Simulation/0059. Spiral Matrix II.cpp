class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n));
		int v = 0, x = 0, y = -1, d = 0;
		vector<int> dx{ 0, 1, 0, -1 };
		vector<int> dy{ 1, 0, -1, 0 };
		int a = n, b = n;
		while (a)
		{
			for (int k = 0; k < a; ++k)
			{
				++v;
				x += dx[d], y += dy[d];
				result[x][y] = v;
			}
			d = (d + 1) % 4;
			swap(a, b);
			--a;
		}
		return result;
	}
};