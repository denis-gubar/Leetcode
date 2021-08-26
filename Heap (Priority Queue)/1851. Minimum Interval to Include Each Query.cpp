class Solution {
public:
	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		int Q = queries.size();
		int I = intervals.size();
		vector<int> result(Q, -1);
		set<pair<int, int>> P;
		for (int i = 0; i < Q; ++i)
			P.insert({ queries[i], i });
		vector<pair<int, int>> A(I);
		for (int i = 0; i < I; ++i)
			A[i] = { intervals[i][1] - intervals[i][0] + 1, intervals[i][0] };
		sort(A.begin(), A.end());
		for (int i = 0; i < I; ++i)
		{
			int const& size = A[i].first;
			int const& left = A[i].second;
			int right = left + size - 1;
			auto it = P.lower_bound({ left, 0 });
			while (it != P.end())
			{
				if (it->first <= right)
				{
					result[it->second] = size;
					it = P.erase(it);
				}
				else
					break;
			}
		}
		return result;
	}
};