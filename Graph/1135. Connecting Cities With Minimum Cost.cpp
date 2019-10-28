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


class Solution {
public:
	int minimumCost(int N, vector<vector<int>>& conections) {
		int result = 0;
		vector<int> visited(N);
		sort(conections.begin(), conections.end(),
			[](vector<int> const& a, vector<int> const& b)
			{
				return a[2] < b[2];
			});
		UnionFind unionFind(N);
		for (vector<int> const& conection : conections)
		{
			int p = conection[0] - 1, q = conection[1] - 1;
			if (!unionFind.find(p, q))
			{
				unionFind.unite(p, q);
				result += conection[2];
			}
		}
		for (int i = 0; i < N; ++i)
			if (unionFind.root(i) != unionFind.root(0))
				return -1;
		return result;
	}
};