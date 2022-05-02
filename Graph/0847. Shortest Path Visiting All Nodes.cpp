class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		int N = graph.size();
		constexpr int INF = 1 << 20;
		int result = INF;
		vector<vector<int>> F(N, vector<int>(1 << N, INF));
		queue<int> Q;
		for (int i = 0; i < N; ++i)
		{
			int V = i, state = 1 << i;
			F[V][state] = 0;
			Q.push(V); Q.push(state);
		}
		while (!Q.empty())
		{
			int V = Q.front(); Q.pop();
			int state = Q.front();  Q.pop();
			for (int U : graph[V])
				if (F[U][state | (1 << U)] > F[V][state] + 1)
				{
					F[U][state | (1 << U)] = F[V][state] + 1;
					Q.push(U); Q.push(state | (1 << U));
				}
		}
		for (int i = 0; i < N; ++i)
			result = min(result, F[i].back());
		return result;
	}
};
