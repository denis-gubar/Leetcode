class Solution {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b)
			{
				if (a[0] != b[0])
					return a[0] < b[0];
				return a[1] > b[1];
			});
		vector<int> M;
		for (vector<int> const& env : envelopes)
		{
			int const& y = env[1];
			auto it = lower_bound(M.begin(), M.end(), y);
			if (it == M.end())
				M.push_back(y);
			else
				*it = y;
		}
		return M.size();
	}
};