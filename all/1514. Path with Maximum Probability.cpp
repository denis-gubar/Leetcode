class Solution {
public:
	template<typename Distance, typename NodeIndex>
	vector<Distance> dijkstra(const vector<vector<pair<NodeIndex, Distance>>>& connectivity, int source)
	{
		const Distance MIN = numeric_limits<Distance>::lowest();
		int N = connectivity.size();
		vector<Distance> minDistance(N + 1, MIN);
		minDistance[source] = 0;
		set<pair<Distance, NodeIndex>, greater<>> activeVertices;
		activeVertices.insert({ 0, source });
		while (!activeVertices.empty())
		{
			int node = activeVertices.begin()->second;
			activeVertices.erase(activeVertices.begin());
			for (auto edge : connectivity[node])
				if (minDistance[edge.first] < minDistance[node] + edge.second)
				{
					activeVertices.erase({ minDistance[edge.first], edge.first });
					minDistance[edge.first] = minDistance[node] + edge.second;
					activeVertices.insert({ minDistance[edge.first], edge.first });
				}
		}
		return minDistance;
	}
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		vector<vector<pair<int, double>>> connectivity(n);
		for (int i = 0; i < edges.size(); ++i)
		{
			connectivity[edges[i][0]].emplace_back(edges[i][1], log(succProb[i]));
			connectivity[edges[i][1]].emplace_back(edges[i][0], log(succProb[i]));
		}
		vector<double> maxDistance = dijkstra(connectivity, start);
        if (maxDistance[end] == numeric_limits<double>::lowest())
            return 0.0;
		return exp(maxDistance[end]);
	}
};