class Solution {
public:
	vector<string> maxNumOfSubstrings(string s) {
		vector<string> result;
		int N = s.size();
		vector<vector<int>> sum(N + 1, vector<int>(26));
		vector<int>	first(26, -1), last(26, -1);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < 26; ++j)
				sum[i + 1][j] += sum[i][j];
			int x = s[i] - 'a';
			++sum[i + 1][x];
			if (first[x] < 0)
				first[x] = i;
			last[x] = i;
		}
		vector<pair<int, int>> P;
		for (int start = 0; start < 26; ++start)
			if (first[start] >= 0)
				for (int finish = 0; finish < 26; ++finish)
					if (first[finish] >= 0)
					{
						int a = first[start], b = last[finish];
						if (a > b) continue;
						bool noIntersection = true;
						for (int j = 0; noIntersection && j < 26; ++j)
							noIntersection = sum[b + 1][j] == sum[N][j] && sum[a][j] == 0
								|| sum[b + 1][j] == sum[a][j];
						if (noIntersection)
							P.emplace_back(b - a + 1, a);
					}
		sort(P.begin(), P.end());
		vector<pair<int, int>> selected;
		for (int i = 0; i < P.size(); ++i)
		{
			bool noIntersection = true;
			int I = P[i].second, J = P[i].first + P[i].second - 1;
			for (auto sel : selected)
			{
				int K = sel.second, L = sel.first + sel.second - 1;
				if (!(J < K || I > L))
				{
					noIntersection = false;
					break;
				}
			}
			if (noIntersection)
				selected.emplace_back(P[i]);
		}
		for (auto sel : selected)
			result.push_back(s.substr(sel.second, sel.first));
		return result;
	}
};