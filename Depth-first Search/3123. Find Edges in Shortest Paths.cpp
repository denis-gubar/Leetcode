static long long const MAX = 1LL << 40;
class Solution {
public:
	template<typename Distance, typename NodeIndex>
	vector<Distance> dijkstra(const vector<vector<pair<NodeIndex, Distance>>>& connectivity, int source)
	{
		int N = connectivity.size();
		vector<Distance> minDistance(N, MAX);
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

    vector<bool> findAnswer(int N, vector<vector<int>>& edges) {
		vector<vector<pair<int, long long>>> connectivity(N);
		for (vector<int> const& e : edges)
		{
			int const& V = e[0];
			int const& U = e[1];
			int const& W = e[2];
			connectivity[V].push_back({ U, W });
			connectivity[U].push_back({ V, W });
		}
		vector<long long> A = dijkstra(connectivity, 0);
		vector<long long > B = dijkstra(connectivity, N - 1);
		int const M = edges.size();
		long long const X = A[N - 1];
		if (X == MAX)
			return vector<bool>(M);
		vector<bool> result;
		result.reserve(M);
		for (vector<int> const& e : edges)
		{
			int const& V = e[0];
			int const& U = e[1];
			long long const W = e[2];
			if (V == 0 && U == N - 1 && A[U] == W || U == 0 && V == N - 1 && A[V] == W)
			{
				result.push_back(true);
				continue;
			}
			if (V == 0 && A[U] == W && A[U] + B[U] == X ||
				U == 0 && A[V] == W && A[V] + B[V] == X ||
				V == N - 1 && B[U] == W && A[U] + B[U] == X || 
				U == N - 1 && B[V] == W && A[V] + B[V] == X)
			{
				result.push_back(true);
				continue;
			}
			if (A[V] + W + B[U] == X || A[U] + W + B[V] == X)
			{
				result.push_back(true);
				continue;
			}
			result.push_back(false);
		}
		return result;
    }
};
