class Solution {
public:
	int maxHeight(vector<vector<int>> cuboids) {
		vector<vector<vector<int>>> A{
			{ {1, 0, 0}, {0, 1, 0}, {0, 0, 1} }, //123
			{ {1, 0, 0}, {0, 0, 1}, {0, 1, 0} }, //132
			{ {0, 1, 0}, {1, 0, 0}, {0, 0, 1} }, //213
			{ {0, 1, 0}, {0, 0, 1}, {1, 0, 0} }, //231
			{ {0, 0, 1}, {1, 0, 0}, {0, 1, 0} }, //312
			{ {0, 0, 1}, {0, 1, 0}, {1, 0, 0} }, //321
		};
		for (vector<int>& c : cuboids)
			sort(c.begin(), c.end());
		sort(cuboids.begin(), cuboids.end());
		int N = cuboids.size();
		auto get = [&cuboids, A](int i, int k)
		{
			vector<int> X{ 0, 0, 0 };
			for (int p = 0; p < 3; ++p)
				for (int q = 0; q < 3; ++q)
					X[p] += cuboids[i][q] * A[k][p][q];
			return X;
		};
		vector<vector<int>> H(N, vector<int>(6));
		for (int i = 0; i < N; ++i)
			for (int ki = 0; ki < 6; ++ki)
			{
				vector<int>	I = get(i, ki);
				H[i][ki] = I[2];
			}
		for (int i = 0; i < N; ++i)
			for (int ki = 0; ki < 6; ++ki)
			{
				vector<int>	I = get(i, ki);
				for (int j = 0; j < i; ++j)
					for (int kj = 0; kj < 6; ++kj)
						if (H[i][ki] < H[j][kj] + I[2])
						{
							vector<int>	J = get(j, kj);
							if (I[0] >= J[0] && I[1] >= J[1] && I[2] >= J[2])
								H[i][ki] = H[j][kj] + I[2];
						}
			}
		int result = 0;
		for (int i = 0; i < N; ++i)
			for (int ki = 0; ki < 6; ++ki)
				result = max(result, H[i][ki]);
		return result;
	}
};