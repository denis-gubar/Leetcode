class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		vector<string> result;
		int N = A.size();
		vector<vector<int>> M(N, vector<int>(127));
		for (int i = 0; i < N; ++i)
			for (char c : A[i])
				++M[i][c];
		for(char j = 0; j < 127; ++j)
			if (M[0][j])
			{
				int m = M[0][j];
				for (int i = 1; i < N; ++i)
					m = min(m, M[i][j]);
				for (int i = 0; i < m; ++i)
					result.push_back(string(1, j));
			}
		return result;
	}
};