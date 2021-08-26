class Solution {
public:
	int longestLine(vector<vector<int>>& A) {
		int result = 0;
		if (A.empty()) return result;
		int N = A.size(), M = A[0].size();
		vector<int>	dx = { 0, 1, 1, 1 };
		vector<int>	dy = { 1, -1, 0, 1 };
		for(int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (A[i][j])
					for (int z = 0; z < 4; ++z)
					{
						int px = i - dx[z];
						int py = j - dy[z];
						if (px >= 0 && px < N && py >= 0 && py < M && A[px][py])
							continue;
						int length = 0;
						while (i + length * dx[z] < N && i + length * dx[z] >= 0 && j + length * dy[z] >= 0 &&
							j + length * dy[z] < M && A[i + length * dx[z]][j + length * dy[z]])
							++length;
						result = max(result, length);
					}
		return result;
	}
};