class Solution {
public:
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int result = 0;
		int N = A.size();
		for(int dx = 1 - N; dx <= N - 1; ++dx)
			for (int dy = 1 - N; dy <= N - 1; ++dy)
			{
				int count = 0;
				for (int x = max(0, -dx), a = x + dx; a < N && x < N; ++x, ++a)
					for (int y = max(0, -dy), b = y + dy; b < N && y < N; ++y, ++b)
						count += A[x][y] && B[a][b];
				result = max(result, count);
			}
		return result;
	}
};