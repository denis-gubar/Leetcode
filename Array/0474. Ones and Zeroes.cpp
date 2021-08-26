class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<vector<int>>> F(2, vector<vector<int>>(m + 1, vector<int>(n + 1)));
		for (int k = 0; k < strs.size(); ++k)
		{
            F[(k + 1) % 2] = F[k % 2];
			int count0 = count(strs[k].begin(), strs[k].end(), '0');
			int count1 = count(strs[k].begin(), strs[k].end(), '1');
			for (int i = count0; i <= m; ++i)
				for (int j = count1; j <= n; ++j)
					F[(k + 1) % 2][i][j] = max(F[(k + 1) % 2][i][j], F[k % 2][i - count0][j - count1] + 1);
		}
		int result = 0;
		for (int k = 0; k < 2; ++k)
			for (int i = 0; i <= m; ++i)
				for (int j = 0; j <= n; ++j)
					result = max(result, F[k][i][j]);
		return result;
	}
};