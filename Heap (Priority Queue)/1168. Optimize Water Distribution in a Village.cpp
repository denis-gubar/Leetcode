class Solution {
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
public:
	int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
		int result = 0;
		UnionFind unionFind(n + 1);
		multiset<vector<int>> S;
		for (int i = 0; i < n; ++i)
			S.insert({ wells[i], i + 1, 0 });
		for (vector<int> pipe : pipes)
        {
            swap(pipe[0], pipe[2]);
			S.insert(pipe);
        }
		for (int i = 0; i < n;)
		{
			auto it = S.begin();
			vector<int> pipe = *it;
			S.erase(it);
			int const& cost = pipe[0];
			int const& V = pipe[2];
			int const& U = pipe[1];
			if (!unionFind.find(U, V))
			{
				unionFind.unite(U, V);
				result += cost;
                ++i;
			}
		}
		return result;
	}
};