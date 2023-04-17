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
	int makeConnected(int n, vector<vector<int>>& connections) {
		if (n > connections.size() + 1)
			return -1;
		UnionFind unionFind(n);
		for (vector<int> const& connection : connections)
			unionFind.checkedUnite(connection[0], connection[1]);
		unordered_set<int> S;
		for (int i = 0; i < n; ++i)
			S.insert(unionFind.root(i));
		return S.size() - 1;
	}
};