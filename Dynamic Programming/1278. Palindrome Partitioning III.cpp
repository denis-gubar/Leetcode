class Solution {
public:
	int calc(string const& s, int start, int end)
	{
		if (start >= end) return F[start][end] = 0;
		int result = F[start][end];
		if (result < 0)
		{
			if (s[start] == s[end])
				result = calc(s, start + 1, end - 1);
			else
				result = 1 + calc(s, start + 1, end - 1);
		}
		return F[start][end] = result;
	}
	int palindromePartition(string s, int k) {
		int N = s.size();
		F = vector<vector<int>>(N, vector<int>(N, -1));
        for(int start = 0; start <= N - 1; ++start)
            for(int end = start; end < N; ++end)
		        calc(s, start, end);
		vector<vector<int>> M(N + 1, vector<int>(k + 1, N));
		M[0][1] = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 1; j <= k; ++j)
				for (int start = 0; start <= i; ++start)
					if (start == i && j == 1)
						M[i + 1][j] = min(M[i + 1][j], F[0][i]);
					else if (start < i && j > 1)
						M[i + 1][j] = min(M[i + 1][j], M[start + 1][j - 1] + F[start + 1][i]);
		return M[N][k];				
	}
	vector<vector<int>> F;
};