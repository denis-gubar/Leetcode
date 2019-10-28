class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
        if (trust.empty())
            return 1;
		vector<int> A(N + 1), T(N + 1);
		for (int i = 0; i < trust.size(); ++i)
			++A[trust[i][1]], ++T[trust[i][0]];
		vector<pair<int, int>> P;
		for (int i = 1; i <= N; ++i)
			P.push_back({ -A[i], i });
		sort(P.begin(), P.end());
		if (P[0].first == P[1].first || -P[0].first + 1 != N || T[P[0].second])
			return -1;
		return P[0].second;
	}
};