class Solution {
public:
	template<typename Distance, typename NodeIndex>
	vector<Distance> dijkstra(const vector<vector<pair<NodeIndex, Distance>>>& connectivity, vector<int> const& disappear)
	{
		const Distance MAX = numeric_limits<Distance>::max();
		int N = connectivity.size();
		vector<Distance> minDistance(N, MAX);
		minDistance[0] = 0;
		set<pair<Distance, NodeIndex>> activeVertices;
		activeVertices.insert({ 0, 0 });
		while (!activeVertices.empty())
		{
			int node = activeVertices.begin()->second;
			activeVertices.erase(activeVertices.begin());
			for (auto edge : connectivity[node])
				if (minDistance[edge.first] > minDistance[node] + edge.second)
				{
					activeVertices.erase({ minDistance[edge.first], edge.first });
					if (minDistance[node] + edge.second < disappear[edge.first])
					{
						minDistance[edge.first] = minDistance[node] + edge.second;
						activeVertices.insert({ minDistance[edge.first], edge.first });
					}
				}
		}
		for (int& X : minDistance)
			if (X == MAX)
				X = -1;
		return minDistance;
	}
	vector<int> minimumTime(int N, vector<vector<int>>& edges, vector<int>& disappear) {
		vector<vector<pair<int, int>>> connectivity(N);
		for (int i = 0; i < edges.size(); ++i)
		{
			connectivity[edges[i][0]].emplace_back(edges[i][1], edges[i][2]);
			connectivity[edges[i][1]].emplace_back(edges[i][0], edges[i][2]);
		}
        return dijkstra(connectivity, disappear);
    }
};
