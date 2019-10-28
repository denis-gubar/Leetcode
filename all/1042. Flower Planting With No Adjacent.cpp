class Solution {
public:
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<int> result(N);
		vector<vector<int>> connectivity(N);
		for (vector<int> const& path : paths)
		{
			connectivity[path[0] - 1].push_back(path[1] - 1);
			connectivity[path[1] - 1].push_back(path[0] - 1);
		}
		for (int start = 0; start < N; ++start)
			if (!result[start])
			{
				result[start] = 1;
				queue<int> q;
				q.push(start);
				while (!q.empty())
				{
					int v = q.front(); q.pop();
					for (int u : connectivity[v])
						if (!result[u])
						{
							vector<int> colors(5);
							for (int a : connectivity[u])
								++colors[result[a]];
							int color = 1;
							while (colors[color])
								++color;
							result[u] = color;
							q.push(u);
						}
				}
			}
		return result;
	}
};