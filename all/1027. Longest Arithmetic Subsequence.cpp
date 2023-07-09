class Solution {
public:
	int longestArithSeqLength(vector<int>& A) {
		int result = 0;
		unordered_map<int, array<int, 1000>> M;
		int N = A.size();
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j)
			{
				int delta = A[j] - A[i];
				if (M.find(delta) == M.end())
					M[delta].fill(0);
				M[delta][j] = max(M[delta][j], M[delta][i] + 1);
				result = max(result, M[delta][j]);
			}
		return result + 1;
	}
};
