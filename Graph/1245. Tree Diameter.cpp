class Solution {
public:
	int treeDiameter(vector<vector<int>>& edges) {
		int result = 0;
		int N = edges.size() + 1;
		vector<vector<int>> connectivity(N);
		for (vector<int> const& edge : edges)
		{
			int const& U = edge[0];
			int const& V = edge[1];
			connectivity[U].push_back(V);
			connectivity[V].push_back(U);
		}
		vector<int> levels(N, N + 1);
		int V = 0;
		levels[V] = 0;
		queue<int> Q;
		Q.push(V);
		while(!Q.empty())
		{
			int V = Q.front(); Q.pop();
			for(int U: connectivity[V])
				if (levels[U] > levels[V] + 1)
				{
					levels[U] = levels[V] + 1;
					Q.push(U);
				}
		}
		int W = max_element(levels.begin(), levels.end()) - levels.begin();
		levels.assign(N, N + 1);
		levels[W] = 0;
		Q.push(W);
		while (!Q.empty())
		{
			int V = Q.front(); Q.pop();
			for (int U : connectivity[V])
				if (levels[U] > levels[V] + 1)
				{
					levels[U] = levels[V] + 1;
					Q.push(U);
				}
		}
		return *max_element(levels.begin(), levels.end());
	}
};