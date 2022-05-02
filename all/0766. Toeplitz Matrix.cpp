class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int N = matrix.size(), M = matrix[0].size();
		unordered_map<int, int> invariant;
		for(int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				int key = j - i;
				auto it = invariant.find(key);
				if (it == invariant.end())
					invariant[key] = matrix[i][j];
				else if (invariant[key] != matrix[i][j])
					return false;
			}
		return true;
	}
};