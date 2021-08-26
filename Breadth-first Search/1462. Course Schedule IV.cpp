class Solution {
public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		vector<bool> result;
		vector<vector<unsigned int>> F(n, vector<unsigned int>(n / 32 + 1));
		for (vector<int> const& pre : prerequisites)
			F[pre[0]][pre[1] >> 5] |= 1 << (pre[1] & 31);
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				if (F[i][k >> 5] & (1 << (k & 31)))
					for (int j = 0; j <= n / 32; ++j)
						F[i][j] = F[i][j] | F[k][j];
		for (vector<int> const& query : queries)
			result.push_back((F[query[0]][query[1] >> 5] & (1 << (query[1] & 31))) > 0);
		return result;
	}
};