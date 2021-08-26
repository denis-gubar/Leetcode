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
	int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
		int N = source.size();
		int result = 0;
		UnionFind uf(N);
		for (vector<int> const& p : allowedSwaps)
			uf.checkedUnite(p[0], p[1]);
		unordered_map<int, vector<int>> M;
		for (int i = 0; i < N; ++i)
			M[uf.root(i)].push_back(i);
		for (auto const& [root, indexes] : M)
		{
			vector<int> A, B, C;
			for (int ind : indexes)
			{
				A.push_back(source[ind]);
				B.push_back(target[ind]);
			}
			sort(A.begin(), A.end());
			sort(B.begin(), B.end());
			set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));
			result += C.size();
		}
		return result;
	}
};