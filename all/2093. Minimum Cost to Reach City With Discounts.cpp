class Solution {
public:
	using Distance = int;
	using NodeIndex = pair<int, int>;
	int minimumCost(int N, vector<vector<int>>& highways, int discounts) {
		vector<vector<pair<int, int>>> connectivity(N);
		for (vector<int> const& e : highways)
		{
			int const& V = e[0];
			int const& U = e[1];
			int const& W = e[2];
			connectivity[V].emplace_back(U, W);
			connectivity[U].emplace_back(V, W);
		}
		int const MAX = 1 << 30;
		vector<vector<int>> minDistance(N, vector<int>(discounts + 1, MAX));
		minDistance[0][0] = 0;
		set<pair<Distance, NodeIndex>> activeVertices;
		activeVertices.insert({ 0, {0, 0} });
		while (!activeVertices.empty())
		{
			NodeIndex node = activeVertices.begin()->second;
			if (node.first == N - 1)
				return activeVertices.begin()->first;
			activeVertices.erase(activeVertices.begin());
			for (auto edge : connectivity[node.first])
			{
				if (minDistance[edge.first][node.second] > minDistance[node.first][node.second] + edge.second)
				{
					activeVertices.erase({ minDistance[edge.first][node.second], node });
					minDistance[edge.first][node.second] = minDistance[node.first][node.second] + edge.second;
					activeVertices.insert({ minDistance[edge.first][node.second], {edge.first, node.second} });
				}
				if (node.second < discounts && minDistance[edge.first][node.second + 1] > minDistance[node.first][node.second] + edge.second / 2)
				{
					activeVertices.erase({ minDistance[edge.first][node.second], node });
					minDistance[edge.first][node.second + 1] = minDistance[node.first][node.second] + edge.second / 2;
					activeVertices.insert({ minDistance[edge.first][node.second + 1], {edge.first, node.second + 1} });
				}
			}
		}
		return -1;
	}
};
