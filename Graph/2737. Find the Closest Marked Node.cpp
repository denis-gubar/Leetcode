class Solution {
public:
	typedef int Distance;
	typedef int NodeIndex;
	vector<bool> marked;
	Distance dijkstra(vector<vector<pair<NodeIndex, Distance>>>& connectivity, int const source)
	{
		Distance const MAX = numeric_limits<Distance>::max();
		int const N = connectivity.size();
		vector<Distance> minDistance(N + 1, MAX);
		minDistance[source] = 0;
		set<pair<Distance, NodeIndex>> activeVertices;
		activeVertices.insert({ 0, source });
		while (!activeVertices.empty())
		{
			int node = activeVertices.begin()->second;
			if (marked[node])
				return minDistance[node];
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
    int minimumDistance(int N, vector<vector<int>>& edges, int s, vector<int>& marked) {
		this->marked = vector<bool>(N);
		for (NodeIndex V : marked)
			this->marked[V] = true;
		vector<vector<pair<NodeIndex, Distance>>> connectivity(N);
		for (vector<int> const& e : edges)
		{
			NodeIndex const& V = e[0];
			NodeIndex const& U = e[1];
			Distance const& D = e[2];
			connectivity[V].emplace_back(U, D);
		}
		return dijkstra(connectivity, s);
    }
};
