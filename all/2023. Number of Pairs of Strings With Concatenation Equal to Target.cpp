class Solution {
public:
	int numOfPairs(vector<string>& nums, string target) {
		int result = 0;
		int T = target.size();
		vector<int> S(101), P(101);
		for (string const& x : nums)
			if (x.size() < T)
			{
				if (equal(target.begin(), target.begin() + x.size(), x.begin(), x.end()))
					++P[x.size()];
				if (equal(target.end() - x.size(), target.end(), x.begin(), x.end()))
					++S[x.size()];
			}
		bool flag = T % 2 == 0 && equal(target.begin(), target.begin() + T / 2, target.begin() + T / 2, target.end());
		for (int i = 1, j = T - 1; i < T; ++i, --j)
			if (i != j || !flag)
				result += S[i] * P[j];
			else if (flag)
				result += S[i] * (S[i] - 1);
		return result;
	}
};