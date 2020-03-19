class Solution {
public:
	int minJumps(vector<int>& arr) {
		int N = arr.size();
		map<int, vector<int>> M;
		for (int i = 0; i < N; ++i)
			M[arr[i]].push_back(i);
		vector<int> F(N, N);
		F[0] = 0;
		queue<int> Q;
		Q.push(0);
		while (!Q.empty())
		{
			int v = Q.front(); Q.pop();
			if (v == N - 1)
				break;
			vector<int> U(M[arr[v]]);
            M[arr[v]].clear();
			U.push_back(v - 1);
			U.push_back(v + 1);
			for (int u : U)
				if (u >= 0 && u < N && F[u] > F[v] + 1 && u != v)
				{
					F[u] = F[v] + 1;
					Q.push(u);
				}
		}
		return F.back();
	}
};