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
	bool gcdSort(vector<int>& nums) {
		int N = nums.size();
		cout << N << '\n';
		vector<pair<int, int>> P(N);
		for (int i = 0; i < N; ++i)
			P[i] = { nums[i], i };
		sort(P.begin(), P.end());
		UnionFind uf(100'001);
		for (int i = 0; i < N; ++i)
		{
			int const& x = P[i].first;
			for(int k = 2; k * k <= x; ++k)
				if (x % k == 0)
				{
					uf.checkedUnite(k, x);
					uf.checkedUnite(x / k, x);
				}
		}
		for (int i = 0; i < N; ++i)
			if (uf.root(P[i].first) != uf.root(nums[i]))
				return false;
		return true;
	}
};