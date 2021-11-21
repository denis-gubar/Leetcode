class Solution {
public:
	bool calc(int a, int b)
	{
		if (a == N + 1 || b == M + 1)
			return a == N + 1 && b == M + 1;
		if (!visited[a][b])
		{
			if (s[a] == p[b] || p[b] == '?')
				result[a][b] = calc(a + 1, b + 1);
			if (p[b] == '*')
				for (int newA = a; !result[a][b] && newA <= N; ++newA)
					result[a][b] = calc(newA, b + 1);
			visited[a][b] = true;
		}
		return result[a][b];
	}
	bool isMatch(string s, string p) {
		N = s.size();
		M = p.size();
		visited = vector<vector<bool>>(N + 1, vector<bool>(M + 1));
		result = vector<vector<bool>>(N + 1, vector<bool>(M + 1));
		this->s = s, this->p = p;
		return calc(0, 0);
	}
	string s, p;
	int N, M;
	vector<vector<bool>> visited, result;
};