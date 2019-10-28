class Solution {
public:
	int maxRepOpt1(string text) {
		int result = 0;
		int N = text.size();
		vector<vector<int>> M(N, vector<int>(26));
		vector<int> totalCount(26);
		for (char c : text)
			++totalCount[c - 'a'];
		M[0][text[0] - 'a'] = 1;
		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < 26; ++j)
				M[i][j] += M[i - 1][j];
			++M[i][text[i] - 'a'];
		}
		int a = 1, b = *max_element(totalCount.begin(), totalCount.end()) + 1;
		while (a + 1 < b)
		{
			bool isPossible = false;
			int m = (b + a) / 2;
			for (int c = 0; !isPossible && c < 26; ++c)
				if (totalCount[c] >= m)
					for (int start = 0; start + m <= N; ++start)
					{
						int x = M[start + m - 1][c] - (start ? M[start - 1][c] : 0);
						if (x == m || x == m - 1 && totalCount[c] > x)
						{
							isPossible = true;
							break;
						}
					}
			if (isPossible)
				a = m;
			else
				b = m;
		}
		return a;
	}
};