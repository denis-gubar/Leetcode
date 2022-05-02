class Solution {
public:
	int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
		int N = flights.size();
		int K = days[0].size();
		vector<vector<int>> F(K + 1, vector<int>(N, -1));
		F[0][0] = 0;
		for(int i = 0; i < K; ++i)
			for(int city = 0; city < N; ++city)
				if (F[i][city] >= 0)
					for(int nextCity = 0; nextCity < N; ++nextCity)
						if (city == nextCity || flights[city][nextCity])
							F[i + 1][nextCity] = max(F[i + 1][nextCity], F[i][city] + days[nextCity][i]);
		int result = 0;
		for (int i = 0; i < N; ++i)
			result = max(result, F[K][i]);
		return result;
	}
};
