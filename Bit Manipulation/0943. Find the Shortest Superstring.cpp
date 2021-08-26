int F[241][13][1 << 12];
class Solution {
public:
	string shortestSuperstring(vector<string>& words) {
		int N = words.size();
		int maxN = 0;
		for (string const& w : words)
			maxN += w.size();
		vector<vector<int>> P(N + 1, vector<int>(N));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (i != j)
					for (int length = 1; length <= words[i].size() && length <= words[j].size(); ++length)
						if (words[i].substr(words[i].size() - length) == words[j].substr(0, length))
							P[i][j] = length;
		memset(F, -1, sizeof(F));
		F[0][N][0] = 1;
		bool flag = true;
		int i, last, mask;
		for (i = 0; i <= maxN; ++i)
		{
			for (last = 0; last <= N; ++last)
			{
				for (mask = 0; flag && (mask < (1 << N)); ++mask)
					if (F[i][last][mask] >= 0)
					{
						if (mask == (1 << N) - 1)
						{
							flag = false;
							break;
						}
						for (int k = 0; k < N; ++k)
							if ((mask & (1 << k)) == 0)
							{
								int const& prefix_length = P[last][k];
								F[i - prefix_length + words[k].size()][k][mask | (1 << k)] = last;
							}
					}
				if (!flag)
					break;
			}
			if (!flag)
				break;
		}
		string result(i, '*');
		while (i > 0)
		{
			int k = last;
			last = F[i][k][mask];
			int const& prefix_length = P[last][k];
			int suffix_length = words[k].size() - prefix_length;
			for (int j = 0; j < suffix_length; ++j)
				result[i - j - 1] = words[k][words[k].size() - j - 1];
			i -= suffix_length;
			mask ^= 1 << k;
		}
		return result;
	}
};