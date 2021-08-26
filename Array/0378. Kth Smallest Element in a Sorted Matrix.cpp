class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int N = matrix.size(), M = matrix[0].size();
		vector<int> pos(N, 0);
		auto comp = [&matrix](pair<int, int> a, pair<int, int> b)
		{
			return matrix[a.first][a.second] > matrix[b.first][b.second];
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> Q(comp);
		for (int i = 0; i < N; ++i)
			Q.emplace(i, 0);
		for (int t = 1; t < k; ++t)
		{
			auto [i, j] = Q.top(); Q.pop();
			if (j + 1 < M)
				Q.emplace(i, j + 1);
		}
		auto const& [i, j] = Q.top();
		return matrix[i][j];
	}
};