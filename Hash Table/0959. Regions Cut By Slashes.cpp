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
	int regionsBySlashes(vector<string>& grid) {
		int N = grid.size();
		UnionFind unionFind(4 * N * N);
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, 1, 0, -1 };
		for(int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
			{
				int key = i * N + j;
				for (int z = 0; z < 4; ++z)
				{
					int nx = i + dx[z];
					int ny = j + dy[z];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N)
						unionFind.checkedUnite(key + z * N * N, nx * N + ny + (z + 2) % 4 * N * N);
				}
				if (grid[i][j] == ' ')
				{
					unionFind.checkedUnite(key, key + N * N);
					unionFind.checkedUnite(key, key + 2 * N * N);
					unionFind.checkedUnite(key, key + 3 * N * N);
				}
				else if (grid[i][j] == '/')
				{
					unionFind.checkedUnite(key, key + 3 * N * N);
					unionFind.checkedUnite(key + N * N, key + 2 * N * N);
				}
				else
				{
					unionFind.checkedUnite(key, key + N * N);
					unionFind.checkedUnite(key + 2 * N * N, key + 3 * N * N);
				}
			}
		map<int, int> M;
		for (int i = 0; i < 4 * N * N; ++i)
			M[unionFind.root(i)] = 1;
		return M.size();
	}
};