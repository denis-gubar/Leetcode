class Solution {
public:
	vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
		vector<int> result;
		vector<int>	A;
		int N = s.size();
		for (int i = 0; i < N; ++i)
			if (s[i] == '|')
				A.push_back(i);
		for (int q = 0; q < queries.size(); ++q)
		{
			int const& left = queries[q][0];
			int const& right = queries[q][1];
			auto L = lower_bound(A.begin(), A.end(), left);
			auto R = upper_bound(A.begin(), A.end(), right);
			int current = 0;
			if (L != A.end() && R != A.begin() && R > L)
			{
				--R;
				current += *R - *L + 1;
				current -= (R - L) + 1;
			}
			result.push_back(current);
		}
		return result;
	}
};