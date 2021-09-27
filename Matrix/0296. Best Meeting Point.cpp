class Solution {
public:
	int minTotalDistance(vector<vector<int>>& grid) {
		int result = 0;
		int N = grid.size(), M = grid[0].size();
		vector<int> X, Y;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				if (grid[i][j])
				{
					X.push_back(i);
					Y.push_back(j);
				}
		int median = X.size() / 2;
		nth_element(X.begin(), X.begin() + median, X.end());
		nth_element(Y.begin(), Y.begin() + median, Y.end());
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (grid[i][j])
					result += abs(X[median] - i) + abs(Y[median] - j);
		return result;
	}
};