class Solution {
public:
	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		vector<int>	result(n);
		vector<unordered_set<int>> connectivity(n);
		vector<int> level(n);
		vector<vector<int>> M(n, vector<int>(26));
		for (vector<int> const& edge : edges)
		{
			connectivity[edge[0]].insert(edge[1]);
			connectivity[edge[1]].insert(edge[0]);
		}
		queue<int> Q;
		Q.push(0);
		while (!Q.empty())
		{
			int V = Q.front(); Q.pop();
			for (int U : connectivity[V])
				if (U && !level[U])
				{
					Q.push(U);
					level[U] = level[V] + 1;
				}
		}
		vector<pair<int, int>> P;
		for (int i = 0; i < n; ++i)
		{
			P.emplace_back(level[i], i);
			++M[i][labels[i] - 'a'];
		}
		sort(P.begin(), P.end(), greater<>());
		for (int i = 0; i < n; ++i)
		{
			auto [L, V] = P[i];
			for (int U : connectivity[V])
				if (level[U] == L - 1)
				{
					for (int z = 0; z < 26; ++z)
						M[U][z] += M[V][z];
					connectivity[V].erase(U);
					connectivity[U].erase(V);
					break;
				}
		}
		for (int i = 0; i < n; ++i)
			result[i] = M[i][labels[i] - 'a'];
		return result;
	}
};