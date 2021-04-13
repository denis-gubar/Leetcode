class Solution {
public:
	int minSideJumps(vector<int>& obstacles) {
		int N = obstacles.size();
		vector<vector<int>> F(2, vector<int>(3));
		F[0][0] = F[0][2] = 1;
		int INF = 1'000'000;
		for (int i = 1; i < N; ++i)
		{
			F[i % 2] = vector<int>(3, INF);
			int lane = obstacles[i] - 1;
			for (int prev = 0; prev < 3; ++prev)
				for (int next = 0; next < 3; ++next)
					if (lane != next)
						F[i % 2][next] = min(F[i % 2][next], 
							F[(i + 1) % 2][prev] + 
							(prev != next) + 
							(next + 1 == obstacles[i - 1]) * INF);
		}
		return *min_element(F[(N - 1) % 2].begin(), F[(N - 1) % 2].end());
	}
};