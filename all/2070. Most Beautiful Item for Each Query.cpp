class Solution {
public:
	vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
		sort(items.begin(), items.end(), [](vector<int> const& a, vector<int> const& b)
			{
				if (a[0] != b[0])
					return a[0] < b[0];
				return a[1] > b[1];
			});
		int beauty = 0;
		int N = items.size();
		int Q = queries.size();
		vector<int> result(Q);
		vector<int> P{ 0 }, B{ 0 };
		for (int i = 0; i < N; ++i)
			if (items[i][1] > beauty)
			{
				beauty = items[i][1];
				P.push_back(items[i][0]);
				B.push_back(beauty);
			}
		for (int i = 0; i < Q; ++i)
		{
			int pos = (upper_bound(P.begin(), P.end(), queries[i]) - P.begin()) - 1;
			result[i] = B[pos];
		}
		return result;
	}
};