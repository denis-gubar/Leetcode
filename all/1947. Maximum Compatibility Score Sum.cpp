class Solution {
public:
	int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
		int result = 0;
		int N = students.size(), M = students[0].size();
		vector<int> A(N);
		iota(A.begin(), A.end(), 0);
		do 
		{
			int current = 0;
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
					current += students[i][j] == mentors[A[i]][j];
			result = max(result, current);
		} while (next_permutation(A.begin(), A.end()));
		return result;
	}
};