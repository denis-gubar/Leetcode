class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		vector<vector<int>> result(mat);
		map<int, vector<int>> A;
		int N = mat.size(), M = mat[0].size();
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				A[i - j].push_back(mat[i][j]);
		for (auto& a : A)
			sort(a.second.begin(), a.second.end(), greater<int>());
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				result[i][j] = A[i - j].back();
				A[i - j].pop_back();
			}
		return result;
	}
};