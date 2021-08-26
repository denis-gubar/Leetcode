class Solution {
public:
	struct UnionFind
	{
		vector<int> id;
		vector<int> sy;

		UnionFind(int N) : id(vector<int>(N)), sy(vector<int>(N, 1))
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
			if (sy[i] < sy[j])
			{
				id[i] = j; sy[j] += sy[i];
			}
			else
			{
				id[j] = i; sy[i] += sy[j];
			}
		}
		void checkedUnite(int p, int q)
		{
			if (!find(p, q))
				unite(p, q);
		}
	};
	int removeStones(vector<vector<int>>& stones) {
		int N = stones.size();
		int result = 0;
		UnionFind unionFind(N);
		unordered_map<int, int> H, V;
		for (int i = 0; i < N; ++i)
		{
			int const& x = stones[i][0];
			int const& y = stones[i][1];
			auto it = H.find(x);
			if (it != H.end())
			{
				if (!unionFind.find(it->second, i))
				{
					unionFind.unite(it->second, i), ++result;
				}
			}
			else
				H[x] = i;
			it = V.find(y);
			if (it != V.end())
			{
				if (!unionFind.find(it->second, i))
				{
					unionFind.unite(it->second, i), ++result;
				}
			}
			else
				V[y] = i;
		}
		return result;
	}
};