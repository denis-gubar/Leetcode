class Solution {
public:
	long long maxPoints(vector<vector<int>>& points) {
		int N = points.size(), M = points[0].size();
		vector<vector<long long>> F(N, vector<long long>(M));
		for (int j = 0; j < M; ++j)
			F[0][j] = points[0][j];
		for (int i = 1; i < N; ++i)
			{
				multiset<long long> R;
				long long L = 0;
				for (int j = 0; j < M; ++j)
					R.insert(F[i - 1][j] - j);
				for (int j = 0; j < M; ++j)
				{
					F[i][j] = max(*R.rbegin() + j, L - j);
					F[i][j] += points[i][j];
					R.erase(R.find(F[i - 1][j] - j));
					L = max(L, F[i - 1][j] + j);
				}
			}
		long long result = *max_element(F.back().begin(), F.back().end());
		return result;
	}
};