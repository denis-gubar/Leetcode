class Solution {
public:
	int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
		int result = 0;
		int N = dist.size();
		vector<pair<int, int>> P(N);
		for (int i = 0; i < N; ++i)
			P[i] = { dist[i], speed[i] };
		sort(P.begin(), P.end(), [](pair<int, int> a, pair<int, int> b)
			{
				return 1LL * a.first * b.second < 1LL * b.first * a.second;
			});
		for (int t = 0; t < N; ++t)
		{
			int const& d = P[t].first;
			int const& s = P[t].second;
			if (d - s * t > 0)
				++result;
            else
                break;
		}
		return result;
	}
};