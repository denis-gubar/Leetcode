class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		int MAX = 1'000'000'000;
		vector<vector<pair<int, int>>> connectivity(N + 1);
		for (vector<int> const& time : times)
			connectivity[time[0]].emplace_back(time[1], time[2]);
		vector<int>	minDistance(N + 1, MAX);
		minDistance[K] = 0;
		set<pair<int, int>> activeVertices;
		activeVertices.emplace(0, K);
		while (!activeVertices.empty())
		{
			int node = activeVertices.begin()->second;
			activeVertices.erase(activeVertices.begin());
			for(auto edge: connectivity[node])
				if (minDistance[edge.first] > minDistance[node] + edge.second)
				{
					activeVertices.erase({ minDistance[edge.first], edge.first });
					minDistance[edge.first] = minDistance[node] + edge.second;
					activeVertices.insert({ minDistance[edge.first], edge.first });
				}
		}
		auto it = *max_element(minDistance.begin() + 1, minDistance.end());
		if (it >= MAX)
			return -1;
		return it;
	}
};