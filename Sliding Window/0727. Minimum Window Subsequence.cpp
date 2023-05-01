static short F[20'001][101];
class Solution {
public:
	string minWindow(string const& S, string const& T) {
		short N = S.size(), M = T.size();
		memset(F, 126, sizeof(F));
		short INF = F[0][0];
		for (short i = 0; i < N; ++i)
		{
			F[i][0] = 0;
			for (short j = 0; j < M; ++j)
				if (F[i][j] < INF)
				{
					F[i + 1][j + (S[i] == T[j])] = min<short>(F[i + 1][j + (S[i] == T[j])], F[i][j] + 1);
				}
		}
		short length = INF, start = 0;
		for (short i = 0; i <= N; ++i)
		{
			if (F[i][M] < length)
				length = F[i][M], start = i - length;
		}
		if (length == INF)
			return {};
		return S.substr(start, length);
	}
};