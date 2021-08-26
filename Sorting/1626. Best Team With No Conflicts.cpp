class Solution {
public:
	int bestTeamScore(vector<int>& scores, vector<int>& ages) {
		int result = 0;
		int N = scores.size();
		vector<pair<int, int>> P(N);
		for (int i = 0; i < N; ++i)
			P[i] = { scores[i], ages[i] };
		vector<int> F(1'001);
		sort(P.begin(), P.end());
		for (int i = 0; i < N; ++i)
			for (int a = P[i].second; a >= 0; --a)
				F[P[i].second] = max(F[P[i].second], F[a] + P[i].first);
		return *max_element(F.begin(), F.end());
	}
};