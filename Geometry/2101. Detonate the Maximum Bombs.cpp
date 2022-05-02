class Solution {
public:
	int maximumDetonation(vector<vector<int>>& bombs) {
		int result = 0;
		int N = bombs.size();
		vector<bitset<100>> F(N);
		for(int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
			{
				int const& xi = bombs[i][0];
				int const& yi = bombs[i][1];
				int const& ri = bombs[i][2];
				int const& xj = bombs[j][0];
				int const& yj = bombs[j][1];
				int const& rj = bombs[j][2];
				F[i][j] = 1LL * (xi - xj) * (xi - xj) + 1LL * (yi - yj) * (yi - yj) <= 1LL * ri * ri;
			}		
		vector<bitset<100>> A(N);
		for(int i = 0; i < N; ++i)
        {
            set<int> S;
		    for (int i = 0; i < N; ++i)
			    S.insert(i);
			if (S.find(i) != S.end())
			{
				S.erase(i);
				queue<int> Q;
				Q.push(i);
				while (!Q.empty())
				{
					int V = Q.front(); Q.pop();
					for(int U : S)
						if (!A[i][U] && F[V][U])
						{
							S.erase(U);
							Q.push(U);
						}
					A[i] |= F[V];
				}
			}
        }
		for (int i = 0; i < N; ++i)
			result = max<int>(result, A[i].count());
		return result;
	}
};