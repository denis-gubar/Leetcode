class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<int> A(n);
		for (int i = 0; i < n; ++i)
			A[i] = i;
		do
		{
			bool isSolution = true;
			vector<int> D1(2 * n), D2(2 * n);
			for(int i = 0; i < n; ++i)
				if (++D1[i + A[i]] == 2 || ++D2[n + i - A[i]] == 2)
				{
					isSolution = false;
					break;
				}
			if (isSolution)
			{
				result.push_back(vector<string>(n, string(n, '.')));
				for (int i = 0; i < n; ++i)
					result.back()[i][A[i]] = 'Q';
			}
		} while (next_permutation(A.begin(), A.end()));
		return result;
	}
};