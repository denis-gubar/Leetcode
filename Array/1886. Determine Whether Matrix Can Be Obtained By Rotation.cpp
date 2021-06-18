class Solution {
public:
	bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
		int result = 0;
		int N = mat.size();
		for (int i = 0; i < 4; ++i)
		{
			if (mat == target)
				return true;
			for(int x = 0; x < N / 2; ++x)
				for (int y = x; y < N - x - 1; ++y)
				{
					int temp = mat[x][y];
					mat[x][y] = mat[y][N - 1 - x];
					mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];
					mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];
					mat[N - 1 - y][x] = temp;
				}
		}
		return false;
	}
};