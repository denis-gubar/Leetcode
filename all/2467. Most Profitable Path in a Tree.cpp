class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int const INF = 1'000'000'000;
		int N = edges.size() + 1;
		vector<int> F(N, -INF);
		vector<bool> aVisited(N), bVisited(N);
		vector<vector<int>> connectivity(N);
		vector<int> Path(N, -1);
		for(int i = 0; i < N - 1; ++i)
		{
			int const& V = edges[i][0];
			int const& U = edges[i][1];
			connectivity[V].push_back(U);
			connectivity[U].push_back(V);
		}
		queue<int> Q;
		Q.push(bob);
		bVisited[bob] = true;
		while(!Q.empty())
		{
			int V = Q.front(); Q.pop();
			if (V == 0)
				break;
			for(int U : connectivity[V])
				if (!bVisited[U])
				{
					Path[U] = V;
					bVisited[U] = true;
					Q.push(U);
				}
		}
		vector<int> P;
		for(int V = 0; V != -1; V = Path[V])
			P.push_back(V);
		vector<int> aQ;
		aQ.push_back(0);
		aQ.push_back(0);
		aVisited[0] = true;
		while(!aQ.empty())
		{
			vector<int> naQ;
			int B = -1;
			if (!P.empty())
			{
				B = P.back(); P.pop_back();
			}
			for(int i = 0; i < aQ.size(); i += 2)
			{
				int const& V = aQ[i];
				int const& total = aQ[i + 1];
				if (V != B)
					F[V] = total + amount[V];
				else
					F[V] = total + amount[V] / 2;
				for(int U : connectivity[V])
					if (!aVisited[U])
					{
						aVisited[U] = true;
						naQ.push_back(U);
						naQ.push_back(F[V]);
					}
			}
			if (B != -1)
				amount[B] = 0;
			aQ = move(naQ);
		}
		F[0] = -INF;
		for(int V = 1; V < N; ++V)
			if (connectivity[V].size() > 1)
				F[V] = -INF;
		return *max_element(F.begin(), F.end());
    }
};
