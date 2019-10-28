class Solution {
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		vector<vector<int>> result;
		vector<set<int>> connectivity(n);
		for (vector<int> const& connection : connections)
		{
			int const& V = connection[0];
			int const& U = connection[1];
			connectivity[V].insert(U);
			connectivity[U].insert(V);
		}
		vector<int> visited(n);
		queue<int> Q;
		for (int i = 0; i < n; ++i)
			if (connectivity[i].size() == 1)
				Q.push(i), visited[i] = 1;
		while (!Q.empty())
		{
			int V = Q.front(); Q.pop();
			int U = *connectivity[V].begin();
			result.push_back({ min(U, V), max(U, V) });
			connectivity[U].erase(V);
			if (!visited[U] && connectivity[U].size() == 1)
					Q.push(U), visited[U] = 1;
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};