class Solution {
public:
	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		map<vector<int>, int> M;
		for (vector<int> const& row : matrix)
		{
			vector<int> A, B;
			for (int i = 0; i < row.size(); ++i)
				A.push_back(row[i]), B.push_back(1 - row[i]);
			if (A[0])
				++M[A];
			else
				++M[B];
		}
		int result = 0;
		for (auto const& p : M)
			result = max(result, p.second);
		return result;
	}
};