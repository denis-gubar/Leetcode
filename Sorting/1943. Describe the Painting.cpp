class Solution {
public:
	vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
		vector<vector<long long>> result;
		int N = segments.size();
		vector<pair<int, int>> P;
		for (int i = 0; i < N; ++i)
		{
			int const& start = segments[i][0];
			int const& end = segments[i][1];
			int const& color = segments[i][2];
			P.emplace_back(start, color);
			P.emplace_back(end, -color);
		}
		sort(P.begin(), P.end());
		long long balance = 0;
		int pos = 0;
		for (int i = 0; i < 2 * N; ++i)
		{
			if (pos != P[i].first && balance > 0)
				result.push_back(vector<long long>{0LL + pos, 0LL + P[i].first, balance});
			balance += P[i].second;
			pos = P[i].first;
		}
		return result;
	}
};