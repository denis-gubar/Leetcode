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
	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
		vector<int> result;
		unordered_map<int, int> M;
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, -1, 0, 1 };
		int k = 0, count = 0;
		UnionFind unionFind(m * n);
		for (pair<int, int> p : positions)
		{
			int x = p.first, y = p.second;
			int key = x * n + y;
			M[key] = k;
			++k;
			++count;
			for (int z = 0; z < 4; ++z)
			{
				int nx = x + dx[z];
				int ny = y + dy[z];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n)
				{
					int newKey = nx * n + ny;
					if (M.find(newKey) != M.end() && !unionFind.find(key, newKey))
					{
						--count;
						unionFind.unite(key, newKey);
					}
				}
			}
			result.push_back(count);
		}
		return result;
	}
};