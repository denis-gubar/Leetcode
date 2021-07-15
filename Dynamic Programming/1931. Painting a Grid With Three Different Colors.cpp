class Solution {
public:
	int colorTheGrid(int m, int n) {
		int const MOD = 1'000'000'007;
		long long result = 0;
		int count = 1;
		for (int i = 0; i < m; ++i)
			count *= 3;
		auto decode = [m](int mask)
		{
			vector<int> line(m);
			int x = mask;
			for (int k = 0; k < m; ++k)
			{
				line[m - 1 - k] = x % 3;
				x /= 3;
			}
			return line;
		};
		vector<vector<int>> lines;
		for (int mask = 0; mask < count; ++mask)
		{
			vector<int>	line = decode(mask);
			bool isOk = true;
			for (int i = 1; i < m; ++i)
				isOk &= line[i] != line[i - 1];
			if (isOk)
				lines.push_back(line);
		}
		int lineCount = lines.size();
		vector<vector<int>> F(lineCount);
		for (int a = 0; a < lineCount; ++a)
			for (int b = 0; b < lineCount; ++b)
			{
				bool isOk = true;
				for (int i = 0; i < m; ++i)
					isOk &= lines[a][i] != lines[b][i];
				if (isOk)
					F[a].push_back(b);
			}
		vector<vector<int>> A(lineCount, vector<int>(n));
		for (int i = 0; i < lineCount; ++i)
			A[i][0] = 1;
		for (int i = 1; i < n; ++i)
			for (int prev = 0; prev < lineCount; ++prev)
				for (int next : F[prev])
				{
					A[next][i] += A[prev][i - 1];
					if (A[next][i] >= MOD)
						A[next][i] -= MOD;
				}
		for (int i = 0; i < lineCount; ++i)
			result += A[i][n - 1];
		return result % MOD;
	}
};