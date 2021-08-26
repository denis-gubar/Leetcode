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
	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
		int result = 0;
		UnionFind A(n), B(n);
		for (vector<int> const& e : edges)
			if (e[0] == 3)
			{
				if (!A.find(e[1] - 1, e[2] - 1))
				{
					A.unite(e[1] - 1, e[2] - 1);
					B.unite(e[1] - 1, e[2] - 1);
					++result;
				}
			}
		for (vector<int> const& e : edges)
		{
			if (e[0] == 1)
			{
				if (!A.find(e[1] - 1, e[2] - 1))
				{
					A.unite(e[1] - 1, e[2] - 1);
					++result;
				}
			}
			if (e[0] == 2)
			{
				if (!B.find(e[1] - 1, e[2] - 1))
				{
					B.unite(e[1] - 1, e[2] - 1);
					++result;
				}
			}
		}
		if (A.sz[A.root(0)] == n && B.sz[B.root(0)] == n)
			result = edges.size() - result;
		else
			result = -1;
		return result;
	}
};