class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		int INF = 1'000'000'000;
        ++K;
		vector<vector<pair<int, int>>> connectivity(n);
		for (vector<int> const& f : flights)
			connectivity[f[0]].emplace_back(f[1], f[2]);
		vector<vector<int>> F(K + 1, vector<int>(n, INF));
		F[0][src] = 0;
		queue<int> Q;
		Q.push(0); Q.push(src);
		while (!Q.empty())
		{
			int k = Q.front(); Q.pop();
			int V = Q.front(); Q.pop();
			if (k == K) continue;
			for (pair<int, int> U : connectivity[V])
				if (F[k][V] + U.second < F[k + 1][U.first])
				{
					F[k + 1][U.first] = F[k][V] + U.second;
					Q.push(k + 1); Q.push(U.first);
				}
		}
		int result = F[0][dst];
		for (int k = 1; k <= K; ++k)
			result = min(result, F[k][dst]);
		if (result == INF)
			result = -1;
		return result;
	}
};