class Solution {
public:
	string minWindow(string S, string T) {
		int N = S.size(), M = T.size();
		int INF = N + 1;
		vector<vector<int>> F(N + 1, vector<int>(M + 1, INF));
		for(int i = 0; i < N; ++i)
        {
            F[i][0] = 0;
			for(int j = 0; j < M; ++j)
				if (F[i][j] < INF)
				{
					F[i + 1][j + (S[i] == T[j])] = min(F[i + 1][j + (S[i] == T[j])], F[i][j] + 1);
				}
        }
		int length = INF, start = 0;
		for (int i = 0; i <= N; ++i)
        {
			if (F[i][M] < length)
				length = F[i][M], start = i - length;
        }
        if (length == INF)
            return {};
		return S.substr(start, length);
	}
};