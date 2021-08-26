class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> result;
		vector<pair<int, int>> P;
		for (vector<int> const& interval : intervals)
		{
			P.emplace_back(interval[0], -1);
			P.emplace_back(interval[1], 1);
		}
		sort(P.begin(), P.end());
		int balance = 0, start = 0;
		for (auto p : P)
		{
			if (p.second == -1)
			{
				if (++balance == 1)
					start = p.first;
			}
			else
			{
				if (--balance == 0)
					result.push_back({ start, p.first });
			}
		}
		return result;
	}
};