class Solution {
public:
	vector<int> z_function(string const& s)
	{
		int N = s.size();
		vector<int> z(N);
		for (int i = 1, L = 0, R = 1; i < N; ++i)
		{
			if (i < R)
				z[i] = min(R - i, z[i - L]);
			while (i + z[i] < N && s[z[i]] == s[i + z[i]])
				++z[i];
			if (i + z[i] > R)
				L = i, R = i + z[i];
		}
		return z;
	}
    int countCells(vector<vector<char>>& grid, string pattern) {
        int const N = grid.size(), M = grid[0].size(), P = pattern.size();
		string H, V;
		H.reserve(N * M);
		V.reserve(N * M);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				H += grid[i][j];
		for (int j = 0; j < M; ++j)
			for (int i = 0; i < N; ++i)
				V += grid[i][j];
		string HP = pattern + '|' + H;
		string VP = pattern + '|' + V;
		vector<int> HZ = z_function(HP);
		vector<int> VZ = z_function(VP);
		int result = 0;
		set<int> HS, VS;
		for(int x = P + 1; x < P + N * M + 1; ++x)
			if (HZ[x] == P)
			{
				int z = x - P - 1;
				int i = z / M, j = z % M;
				HS.insert(z);
			}
		for (int x = P + 1; x < P + N * M + 1; ++x)
			if (VZ[x] == P)
			{
				int z = x - P - 1;
				int i = z % M, j = z / M;
				VS.insert(z);
			}
		for(int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				int hx = i * M + j;
				int hz = -1;
				if (auto it = HS.lower_bound(hx - P + 1); it != HS.end())
				{
					if (*it <= hx)
						hz = *it;
				}
				if (hz == -1)
					continue;
				int vx = j * N + i;
				int vz = -1;
				if (auto it = VS.lower_bound(vx - P + 1); it != VS.end())
				{
					if (*it <= vx)
						vz = *it;
				}
				if (vz == -1)
					continue;
				++result;
			}
        return result;
    }
};
