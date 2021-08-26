class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int N = matrix.size(), M = matrix[0].size();
		for (int i = 0; i < N; ++i)
			if (matrix[i][0] <= target && binary_search(matrix[i].begin(), matrix[i].end(), target))
				return true;
		return false;
	}
};