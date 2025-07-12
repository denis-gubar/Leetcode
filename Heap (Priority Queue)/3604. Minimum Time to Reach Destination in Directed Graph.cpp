class Solution {
public:
	using EdgeIndex = int;
	using NodeIndex = int;
	using Distance = int;
	Distance dijkstra(vector<vector<EdgeIndex>> const& connectivity, vector<vector<int>> const& edges)
	{
		int const source = 0;
		Distance const MAX = numeric_limits<Distance>::max();
		int const N = connectivity.size();
		vector<Distance> minDistance(N + 1, MAX);
		minDistance[source] = 0;
		set<pair<Distance, NodeIndex>> activeVertices;
		activeVertices.insert({ 0, source });
		while (!activeVertices.empty())
		{
			int node = activeVertices.begin()->second;
			activeVertices.erase(activeVertices.begin());
			for (auto edge : connectivity[node])
			{
				NodeIndex const& V = edges[edge][0];
				NodeIndex const& U = edges[edge][1];
				Distance const& start = edges[edge][2];
				Distance const& end = edges[edge][3];
				if (minDistance[V] > end)
					continue;
				if (minDistance[U] > max(start, minDistance[V]) + 1)
				{
					activeVertices.erase({ minDistance[U], U });
					minDistance[U] = max(start, minDistance[V]) + 1;
					activeVertices.insert({ minDistance[U], U });
				}
			}
		}
		if (minDistance[N - 1] == MAX)
			minDistance[N - 1] = -1;
		return minDistance[N - 1];
	}
    int minTime(int N, vector<vector<int>>& edges) {
		vector<vector<EdgeIndex>> connectivity(N);
		int const E = edges.size();
		for (int e = 0; e < E; ++e)
		{
			int const& V = edges[e][0];
			connectivity[V].push_back(e);
		}
		return dijkstra(connectivity, edges);
    }
};
