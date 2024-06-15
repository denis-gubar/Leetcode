class Solution {
public:
	long long const MAX = 1LL << 60;
	template<typename Distance, typename NodeIndex>
	Distance dijkstra(vector<vector<pair<NodeIndex, Distance>>> const& connectivity, int source, vector<int> const& appleCost)
	{
		int N = connectivity.size();
		vector<Distance> minDistance(N + 1, MAX);
		minDistance[source] = 0;
		set<pair<Distance, NodeIndex>> activeVertices;
		activeVertices.insert({ 0, source });
		long long result = MAX;
		while (!activeVertices.empty())
		{
			int node = activeVertices.begin()->second;
			activeVertices.erase(activeVertices.begin());
			if (minDistance[node] >= result)
				break;
			result = min(result, minDistance[node] + appleCost[node]);
			for (auto edge : connectivity[node])
				if (minDistance[edge.first] > minDistance[node] + edge.second)
				{
					activeVertices.erase({ minDistance[edge.first], edge.first });
					minDistance[edge.first] = minDistance[node] + edge.second;
					activeVertices.insert({ minDistance[edge.first], edge.first });
				}
		}
		return result;
	}

    vector<long long> minCost(int N, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
		vector<vector<pair<int, long long>>> connectivity(N);
		vector<long long> result(N);
		for (vector<int> const& edge : roads)
		{
			connectivity[edge[0] - 1].push_back({ edge[1] - 1, 1LL * edge[2] * (k + 1)});
			connectivity[edge[1] - 1].push_back({ edge[0] - 1, 1LL * edge[2] * (k + 1)});
		}
		for (int i = 0; i < N; ++i)
			result[i] = dijkstra(connectivity, i, appleCost);
        return result;
    }
};
