class Solution {
public:
	int const INF = 1 << 30;
	int minOperations(vector<vector<int>>& grid, int x) {
		int N = grid.size(), M = grid[0].size();
		vector<int>	A;
		A.reserve(N * M);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				A.push_back(grid[i][j]);
		sort(A.begin(), A.end());
		auto z = *min_element(A.begin(), A.end());
		for (int& k : A)
			k -= z;
		for (int& k : A)
			if (k % x != 0)
				return -1;
			else
				k /= x;
		vector<int> P{ 0 };
		partial_sum(A.begin(), A.end(), back_inserter(P));
		int result = INF;
		for (int i = 0; i < N * M; ++i)
			result = min(result, (A[i] * (i + 1) - P[i + 1]) + (P.back() - P[i] - A[i] * (N * M - i)));
		if (result == INF)
			result = -1;
		return result;
	}
};