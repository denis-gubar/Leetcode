class Solution {
public:
	const int MAX = 1000000007;
	vector<int> dijkstra(const vector<vector<pair<int, int>>>& connectivity, int source, int N)
	{
		vector<int> minDistance(N, MAX);
		minDistance[source] = 0;
		set<pair<int, int>> activeVertices;
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
	int reachableNodes(vector<vector<int>>& edges, int M, int N) {
		int result = 0;
		vector<vector<pair<int, int>>> connectivity(N);
		for (int i = 0; i < edges.size(); ++i)
		{
			connectivity[edges[i][0]].push_back(pair<int, int>{ edges[i][1], edges[i][2] + 1 });
			connectivity[edges[i][1]].push_back(pair<int, int>{ edges[i][0], edges[i][2] + 1 });
		}
		vector<int> distances = dijkstra(connectivity, 0, N);
		for (int i = 0; i < N; ++i)
			if (distances[i] <= M)
				++result;
		for (int i = 0; i < edges.size(); ++i)
		{
			int v = edges[i][0], u = edges[i][1];
			int edgesToAdd = 0;
			if (distances[v] < M)
				edgesToAdd += (M - distances[v]);
			if (distances[u] < M)
				edgesToAdd += (M - distances[u]);
			edgesToAdd = max(min(edgesToAdd, edges[i][2]), 0);
			result += edgesToAdd;
		}
		return result;
	}
};