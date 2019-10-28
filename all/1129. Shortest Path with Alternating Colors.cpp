class Solution {
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		vector<vector<int>> R(n, vector<int>(n)), B(n, vector<int>(n));
		vector<int> result(n, 3 * n);
		for (auto const& edge : red_edges)
			R[edge[0]][edge[1]] = 1;
		for (auto const& edge : blue_edges)
			B[edge[0]][edge[1]] = 1;
		vector<vector<int>> visited(n, vector<int>(2));
		queue<int> Q;
		Q.push(0); Q.push(1); Q.push(0);
		Q.push(0); Q.push(2); Q.push(0);
		visited[0][0] = visited[0][1] = 1;
		while (!Q.empty())
		{
			int v = Q.front(); Q.pop();
			int color = Q.front(); Q.pop();
			int length = Q.front(); Q.pop();
			result[v] = min(result[v], length);
			for(int u = 0; u < n; ++u)
				if (color == 1)
				{
					if (R[v][u] && !visited[u][2 - color])
					{
						visited[u][2 - color] = 1;
						Q.push(u); Q.push(3 - color); Q.push(length + 1);
					}
				}
				else
				{
					if (B[v][u] && !visited[u][2 - color])
					{
						visited[u][2 - color] = 1;
						Q.push(u); Q.push(3 - color); Q.push(length + 1);
					}
				}
		}
		for (int& x : result)
			if (x == 3 * n)
				x = -1;
		return result;
	}
};