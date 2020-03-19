class Solution {
	template<typename Distance, typename NodeIndex>
	int dijkstra(vector<vector<pair<NodeIndex, Distance>>> const& connectivity, int source, int threshold)
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
			if (minDistance[node] > threshold)
				break;
			for (auto edge : connectivity[node])
				if (minDistance[edge.first] > minDistance[node] + edge.second)
				{
					activeVertices.erase({ minDistance[edge.first], edge.first });
					minDistance[edge.first] = minDistance[node] + edge.second;
					activeVertices.insert({ minDistance[edge.first], edge.first });
				}
		}
		int result = -1;
		for (int dist : minDistance)
			if (dist <= threshold)
				++result;
		return result;
	}
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		vector<vector<pair<int, int>>> connectivity(n);
		for (vector<int> const& edge : edges)
		{
			connectivity[edge[0]].push_back({ edge[1], edge[2] });
			connectivity[edge[1]].push_back({ edge[0], edge[2] });
		}
		vector<vector<int>> A;
		for (int i = 0; i < n; ++i)
			A.push_back({dijkstra(connectivity, i, distanceThreshold), -i});
		return -min_element(A.begin(), A.end())->operator[](1);
	}
};