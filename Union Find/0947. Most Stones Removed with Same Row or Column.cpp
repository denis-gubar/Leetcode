struct UnionFind
{
	vector<int> id, sz;
	UnionFind(int N): id(vector<int>(N)), sz(vector<int>(N, 1))
	{
		for (int i = 0; i < N; i++)
			id[i] = i;
	}
	int root(int i)
	{
		while (i != id[i]) 
			i = id[i];
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
};

class Solution {
public:
	int removeStones(vector<vector<int>>& stones) {
		int result = 0;
		int N = stones.size();
		vector<pair<int, int>> X(N), Y(N);
		UnionFind unionFind(N);
		for (int i = 0; i < N; ++i)
		{
			X[i] = { stones[i][0], i };
			Y[i] = { stones[i][1], i };
		}
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		for (int i = 1; i < N; ++i)
			if (X[i - 1].first == X[i].first)
				if (!unionFind.find(X[i - 1].second, X[i].second))
					unionFind.unite(X[i - 1].second, X[i].second);
		for (int i = 1; i < N; ++i)
			if (Y[i - 1].first == Y[i].first)
				if (!unionFind.find(Y[i - 1].second, Y[i].second))
					unionFind.unite(Y[i - 1].second, Y[i].second);
		map<int, int> M;
		for (int i = 0; i < N; ++i)
			++M[unionFind.root(i)];
        for(auto it = M.begin(); it != M.end(); ++it)
            result += it->second - 1;
		return result;
	}
};