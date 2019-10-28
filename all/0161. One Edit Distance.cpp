class Solution {
public:
	bool isOneEditDistance(string s, string t) {
		int S = s.size(), T = t.size();
		vector<vector<int>> M(S + 1, vector<int>(T + 1, max(S, T)));
		for (int i = 0; i <= S; ++i)
			M[i][0] = i;
		for (int j = 0; j <= T; ++j)
			M[0][j] = j;
		for (int i = 1; i <= S; ++i)
			for (int j = max(1, i - 2); j <= min(i + 2, T); ++j)
				if (s[i - 1] == t[j - 1])
					M[i][j] = min(M[i][j], M[i - 1][j - 1]);
				else
					M[i][j] = min({ M[i][j], M[i - 1][j] + 1, M[i][j - 1] + 1, M[i - 1][j - 1] + 1 });
		return M[S][T] == 1;
	}
};