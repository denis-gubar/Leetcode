class Solution {
public:
	bool isPossibleToRearrange(string s, string t, int k) {
        int const N = s.size(), M = N / k;
		vector<string> S, T;
		S.reserve(k);
		T.reserve(k);
		for (int i = 0; i < N; ++i)
		{
			if (i % M == 0)
			{
				S.push_back({});
				S.back().reserve(M);
				T.push_back({});
				T.back().reserve(M);
			}
			S.back() += s[i];
			T.back() += t[i];
		}
		sort(S.begin(), S.end());
		sort(T.begin(), T.end());
		return S == T;
    }
};
