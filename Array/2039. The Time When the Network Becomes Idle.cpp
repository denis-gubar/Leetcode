class Solution {
public:
	template<typename Distance, typename NodeIndex>
	vector<Distance> dijkstra(const vector<vector<pair<NodeIndex, Distance>>>& connectivity, int source)
	{
		const Distance MAX = numeric_limits<Distance>::max();
		int N = connectivity.size();
		vector<Distance> minDistance(N + 1, MAX);
		minDistance[source] = 0;
		set<pair<Distance, NodeIndex>> activeVertices;
		activeVertices.insert({ 0, source });
		while (!activeVertices.empty())
		{
			int node = activeVertices.begin()->second;
			activeVertices.erase(activeVertices.begin());
			for (auto edge : connectivity[node])
				if (minDistance[edge.first] > minDistance[node] + edge.second)
				{
					activeVertices.erase({ minDistance[edge.first], edge.first });
					minDistance[edge.first] = minDistance[node] + edge.second;
					activeVertices.insert({ minDistance[edge.first], edge.first });
				}
		}
		return minDistance;
	}
	int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
		int N = patience.size();
		vector<vector<pair<int, int>>> connectivity(N);
		for (vector<int> const& e : edges)
		{
			int const& V = e[0];
			int const& U = e[1];
			connectivity[V].push_back({ U, 1 });
			connectivity[U].push_back({ V, 1 });
		}
		vector<int> D = dijkstra(connectivity, 0);
		int result = 0;
		for (int V = 1; V < N; ++V)
			if (patience[V] < 2 * D[V])
			{
				if (2 * D[V] % patience[V] == 0)
					result = max(result, 4 * D[V] - patience[V] + 1);
				else
					result = max(result, 4 * D[V] - (2 * D[V] % patience[V]) + 1);
			}
			else
				result = max(result, 2 * D[V] + 1);
		return result;
	}
};