unsigned char F[102][102][27][102];
class Solution {
public:
	int getLengthOfOptimalCompression(string s, int k) {
		int N = s.size();
		unsigned char INF = 120;
		memset(F, INF, sizeof(F));
		F[0][0][0][0] = 0;
		unsigned char result = INF;
		for (int i = 0; i < N; ++i)
			for (int removed = 0, nextC = s[i] - 'a' + 1; removed <= k; ++removed)
				for (int c = 0; c <= 26; ++c)
					for (int count = 0; count <= i; ++count)
						if (F[i][removed][c][count] < INF)
						{
							if (nextC != c)
							{
								F[i + 1][removed][nextC][1] = min<unsigned char>(F[i + 1][removed][nextC][1], F[i][removed][c][count] + 1);
								F[i + 1][removed + 1][c][count] = min<unsigned char>(F[i + 1][removed + 1][c][count], F[i][removed][c][count]);
							}
							else
							{
								F[i + 1][removed][c][count + 1] = min<unsigned char>(F[i + 1][removed][c][count + 1], F[i][removed][c][count] + (count == 1) + (count == 9) + (count == 99));
								F[i + 1][removed + 1][c][count] = min<unsigned char>(F[i + 1][removed + 1][c][count], F[i][removed][c][count]);
							}
						}
		for (int removed = 0; removed <= k; ++removed)
			for (int c = 0; c <= 26; ++c)
				for (int count = 0; count <= N; ++count)
					result = min(result, F[N][removed][c][count]);
		return result;
	}
};
