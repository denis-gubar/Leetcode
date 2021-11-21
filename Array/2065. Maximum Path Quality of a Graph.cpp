class Solution {
public:
	int result;
	int N;
	vector<vector<pair<int, int>>> connectivity;
	vector<int> visited;
	vector<int> values;
	int maxTime;
	int sum;
	int time;
	void dfs(int V)
	{
		if (++visited[V] == 1)
			sum += values[V];
		if (V == 0)
			result = max(result, sum);
		for (auto [U, delta] : connectivity[V])
		{
			time += delta;
			if (time <= maxTime)
				dfs(U);
			time -= delta;
		}
		if (--visited[V] == 0)
			sum -= values[V];
	}
	int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
		result = 0;
		sum = 0;
		time = 0;
		this->maxTime = maxTime;
		this->values = values;
		N = values.size();
		connectivity = vector<vector<pair<int, int>>>(N);
		for (vector<int> const& e : edges)
		{
			int const& V = e[0];
			int const& U = e[1];
			int const& time = e[2];
			connectivity[V].push_back({ U, time });
			connectivity[U].push_back({ V, time });
		}
		visited = vector<int>(N);
        dfs(0);
		return result;
	}
};