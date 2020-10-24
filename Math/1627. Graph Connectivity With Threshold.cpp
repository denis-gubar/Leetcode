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
	vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
		int N = queries.size();
		if (!threshold)
			return vector<bool>(N, true);
		vector<bool> result(N);
		UnionFind uf(n + 1);
		for (int x = threshold + 1; x + x <= n; ++x)
		{
			if (uf.find(x, x + x))
				continue;
			for (int y = x + x; y <= n; y += x)
				uf.checkedUnite(x, y);
		}
		for (int i = 0; i < queries.size(); ++i)
			result[i] = uf.find(queries[i][0], queries[i][1]);
		return result;
	}
};