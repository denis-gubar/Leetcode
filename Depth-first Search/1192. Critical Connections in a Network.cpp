class Solution {
public:
	vector<vector<int>> result;
	vector<int> visited;
	vector<int> depth;
	vector<vector<int>> connectivity;
	void calc(int V, int from, int& level)
	{
		visited[V] = level;
		depth[V] = level;
		++level;
		for (int U : connectivity[V])
			if (U != from)
			{
				if (visited[U] == 0)
					calc(U, V, level);
				depth[V] = min(depth[V], depth[U]);
				if (visited[V] < depth[U])
					result.push_back({ V, U });
			}
	}
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		visited = vector<int>(n);
		depth = vector<int>(n);
		connectivity = vector<vector<int>>(n);
		for (vector<int> const& connection : connections)
		{
			int const& V = connection[0];
			int const& U = connection[1];
			connectivity[V].push_back(U);
			connectivity[U].push_back(V);
		}
		for (int V = 0; V < n; ++V)
			if (visited[V] == 0)
			{
				int level = 1;
				calc(V, -1, level);
			}
		return result;
	}
};