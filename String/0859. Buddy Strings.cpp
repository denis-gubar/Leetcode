class Solution {
public:
	bool buddyStrings(string A, string B) {
		if (A.size() != B.size())
			return false;
		if (A == B)
		{
			sort(A.begin(), A.end());
			return unique(A.begin(), A.end()) != A.end();
		}
		int N = A.size();
		vector<pair<int, int>> P;
		for (int i = 0; i < N; ++i)
			if (A[i] != B[i])
				P.push_back({A[i], B[i]});
		if (P.size() != 2)
			return false;
		return P[0].first == P[1].second && P[0].second == P[1].first;
	}
};