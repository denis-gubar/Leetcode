class Solution {
public:
	vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
		vector<int>	result(n - 1);
		vector<vector<bool>> M(n, vector<bool>(n));
		for (vector<int> const& e : edges)
			M[e[0] - 1][e[1] - 1] = M[e[1] - 1][e[0] - 1] = true;
		for (int mask = 1; mask < (1 << n); ++mask)
		{
			int d = 0;
			int x = mask;
			while (x)
			{
				x &= x - 1;
				++d;
			}
			if (d == 1)
				continue;
			for (int V = 0; V < n; ++V)
				if (mask & (1 << V))
				{
					vector<int>	D(n, n + 1);
					auto calc = [&D, &M, mask, n](int V)
					{
						D[V] = 0;
						queue<int> Q;
						Q.push(V);
						while (!Q.empty())
						{
							V = Q.front(); Q.pop();
							for (int U = 0; U < n; ++U)
								if (M[V][U] && D[U] > D[V] + 1 && (mask & (1 << U)))
								{
									D[U] = D[V] + 1;
									Q.push(U);
								}
						}
						V = 0;
						for (int U = 1; U < n; ++U)
							if (D[U] != n + 1 && (D[U] > D[V] || D[V] == n + 1))
								V = U;
						return V;
					};
					V = calc(V);
					bool flag = true;
					for (int U = 0; U < n; ++U)
						if (D[U] == n + 1 && (mask & (1 << U)))
						{
							flag = false;
							break;
						}
					if (!flag)
						break;
					fill(D.begin(), D.end(), n + 1);
					V = calc(V);
					if (D[V])
					{
						++result[D[V] - 1];
						/*for (int U = 0; U < n; ++U)
							if (mask & (1 << U))
								cout << U + 1;
						cout << " " << D[V] << '\n';*/
					}
					break;
				}
		}
		return result;
	}
};