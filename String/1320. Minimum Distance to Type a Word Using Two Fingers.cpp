class Solution {
public:
	int minimumDistance(string word) {
		vector<vector<int>> distances(26, vector<int>(26));
		for (int a = 0, ax = 0, ay = 0; a < 26; ++a)
		{
			for (int b = 0, bx = 0, by = 0; b < 26; ++b)
			{
				distances[a][b] = abs(ax - bx) + abs(ay - by);
				++by;
				if (by == 6)
				{
					++bx;
					by = 0;
				}
			}
			++ay;
			if (ay == 6)
			{
				++ax;
				ay = 0;
			}
		}
		int result = 100'000;
		int N = word.size();
		vector<vector<vector<int>>> F(N + 1, vector<vector<int>>(26, vector<int>(26, 100'000)));
        for (int a = 0; a < 26; ++a)
            for (int b = 0; b < 26; ++b)
			    F[0][a][b] = 0;
		for (int i = 1; i <= N; ++i)
		{
			int x = word[i - 1] - 'A';
			for (int a = 0; a < 26; ++a)
				for (int b = 0; b < 26; ++b)
                    if (a != b)
				{
					F[i][a][x] = min(F[i][a][x], F[i - 1][a][b] + distances[b][x]);
					F[i][x][b] = min(F[i][x][b], F[i - 1][a][b] + distances[x][a]);
				}
		}
		for (int a = 0; a < 26; ++a)
			for (int b = 0; b < 26; ++b)
				result = min(result, F[N][a][b]);
		return result;
	}
};