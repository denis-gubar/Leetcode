class Solution {
public:
	using NodeIndex = int;
	using Distance = int;
	int minCost(int N, vector<vector<int>>& edges) {
        int const INF = 1 << 30;
		vector<vector<pair<NodeIndex, Distance>>> connectivity(N);		
		for (vector<int> const& e : edges)
		{
			int const& V = e[0];
			int const& U = e[1];
			int const& W = e[2];
			connectivity[V].emplace_back(U, W);
			connectivity[U].emplace_back(V, 2 * W);
		}
		vector<Distance> minDistance(N, INF);
		minDistance[0] = 0;
		set<pair<Distance, NodeIndex>> activeVertices;
		activeVertices.insert({ 0, 0 });
		while (!activeVertices.empty())
		{
			int node = activeVertices.begin()->second;
			if (node == N - 1)
				return minDistance[N - 1];
			activeVertices.erase(activeVertices.begin());
			for (auto edge : connectivity[node])
				if (minDistance[edge.first] > minDistance[node] + edge.second)
				{
					activeVertices.erase({ minDistance[edge.first], edge.first });
					minDistance[edge.first] = minDistance[node] + edge.second;
					activeVertices.insert({ minDistance[edge.first], edge.first });
				}
		}
		return -1;
    }
};
