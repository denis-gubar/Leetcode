class Solution {
public:
	struct UnionFind
	{
		vector<int> id;
		vector<int> sz;

		UnionFind(int N) : id(vector<int>(N)), sz(vector<int>(N, 1))
		{
			for (int i = 0; i < N; ++i)
				id[i] = i;
		}
		int root(int i)
		{
			while (i != id[i])
			{
				id[i] = id[id[i]];
				i = id[i];
			}
			return i;
		}
		bool find(int p, int q)
		{
			return root(p) == root(q);
		}
		void unite(int p, int q)
		{
			int i = root(p);
			int j = root(q);
			if (sz[i] < sz[j])
			{
				id[i] = j; sz[j] += sz[i];
			}
			else
			{
				id[j] = i; sz[i] += sz[j];
			}
		}
		void checkedUnite(int p, int q)
		{
			if (!find(p, q))
				unite(p, q);
		}
	};
	vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
		int qq = queries.size();
		vector<bool> result(qq);
		vector<pair<int, int>> P(qq);
		for (int i = 0; i < qq; ++i)
			P[i] = { queries[i][2], i };
        sort(P.begin(), P.end());
		sort(edgeList.begin(), edgeList.end(), [](vector<int> const& a, vector<int> const& b)
			{
				return a[2] < b[2];
			});
		UnionFind uf(n);
		int j = 0;
		for (int i = 0; i < qq; ++i)
		{
            int k = P[i].second;
			while (j < edgeList.size() && edgeList[j][2] < P[i].first)
			{
				uf.checkedUnite(edgeList[j][0], edgeList[j][1]);
				++j;
			}			
			if (uf.find(queries[k][0], queries[k][1]))
				result[k] = true;
		}
		return result;
	}
};