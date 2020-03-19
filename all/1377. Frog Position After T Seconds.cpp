class Solution {
public:
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		vector<unordered_set<int>> connectivity(n + 1);
		vector<double> visited(n + 1);
		visited[1] = 1.0;
		for (int i = 0; i < edges.size(); ++i)
		{
			connectivity[edges[i][0]].insert(edges[i][1]);
			connectivity[edges[i][1]].insert(edges[i][0]);
		}
		queue<int> Q;
		Q.push(1); Q.push(0);
		while (!Q.empty())
		{
			int v = Q.front(); Q.pop();
			int level = Q.front(); Q.pop();
			for (int u : connectivity[v])
				connectivity[u].erase(v);
			if (level == t) continue;
			if (connectivity[v].size() > 0)
			{
				for (int u : connectivity[v])
				{
					Q.push(u); Q.push(level + 1);
					visited[u] = visited[v] / connectivity[v].size();
				}
				if (v == target) return 0.0;
			}
		}
		return visited[target];
	}
};