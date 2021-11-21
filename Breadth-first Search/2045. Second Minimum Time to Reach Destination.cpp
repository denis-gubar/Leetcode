class Solution {
public:
	int secondMinimum(int N, vector<vector<int>>& edges, int time, int change) {
		int const INF = 1 << 28;
		vector<vector<int>> distance(2, vector<int>(N + 1, INF));
		distance[0][1] = 0;
		distance[1][1] = 2;
		vector<vector<int>> connectivity(N + 1);
		for (vector<int> const& e : edges)
		{
			int const& V = e[0];
			int const& U = e[1];
			connectivity[V].push_back(U);
			connectivity[U].push_back(V);
		}
		auto align = [change](int d)
		{
			if (d % (2 * change) < change)
				return d;
			return (d / (2 * change) + 1) * (2 * change);
		};
		queue<int> Q;
		Q.push(1);
		while (!Q.empty())
		{
			int V = Q.front(); Q.pop();
			int d0 = distance[0][V];
			int d1 = distance[1][V];
			for (int U : connectivity[V])
			{
				bool flag = false;
				if (d0 + 1 < distance[0][U])
				{
					distance[1][U] = min(distance[0][U], d0 + 3);
					distance[0][U] = d0 + 1;
					Q.push(U);
					flag = true;
				}
				else if (d0 + 1 > distance[0][U] && d0 + 1 < distance[1][U])
				{
					distance[1][U] = d0 + 1;
					if (!flag)
					{
						flag = true;
						Q.push(U);
					}
				}
				if (d1 + 1 < distance[1][U])
				{
					distance[1][U] = d1 + 1;
					if (!flag)
						Q.push(U);
				}
			}
		}
		int result = 0;
		for (int k = 0; k < distance[1][N]; ++k)
		{
			result = align(result);
			result += time;
		}
		return result;
	}
};