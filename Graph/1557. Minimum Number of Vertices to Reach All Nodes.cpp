class Solution {
public:
	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
		vector<int>	result;
		vector<vector<int>> inv(n);
		for (vector<int> const& edge : edges)
		{
			const int& V = edge[0];
			const int& U = edge[1];
			inv[U].push_back(V);
		}
		for (int i = 0; i < n; ++i)
			if (inv[i].empty())
				result.push_back(i);
		return result;
	}
};