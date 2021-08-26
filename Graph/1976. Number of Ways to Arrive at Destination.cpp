class Solution {
public:
	int const MOD = 1'000'000'007;
	template<typename Distance, typename NodeIndex>
	vector<int> dijkstra(const vector<vector<pair<NodeIndex, Distance>>>& connectivity, int source)
	{
		const Distance MAX = numeric_limits<Distance>::max();
		int N = connectivity.size();
		vector<int> result(N);
		vector<Distance> minDistance(N + 1, MAX);
		result[source] = 1;
		minDistance[source] = 0;
		set<pair<Distance, NodeIndex>> activeVertices;
		activeVertices.insert(pair<Distance, NodeIndex>{ 0, source });
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
					result[edge.first] = result[node];
				}
				else if (minDistance[edge.first] == minDistance[node] + edge.second)
				{
					result[edge.first] += result[node];
					result[edge.first] %= MOD;
				}
		}
		return result;
	}
	int countPaths(int n, vector<vector<int>>& roads) {
		vector<vector<pair<int, long long>>> connectivity(n);
		for (vector<int> const& e : roads)
		{
			int const& u = e[0];
			int const& v = e[1];
			long long const time = e[2];
			connectivity[u].push_back({ v, time });
			connectivity[v].push_back({ u, time });
		}
		vector<int> D = dijkstra(connectivity, 0);
		return D.back();
	}
};