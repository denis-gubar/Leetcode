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
	int minCostConnectPoints(vector<vector<int>>& points) {
		int result = 0;
		int N = points.size();
		UnionFind uf(N);
		vector<long long> A;
		A.reserve(500'000);
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j)
				A.push_back((abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])) * 1'000'000LL + i * 1'000LL + j);
		sort(A.begin(), A.end());
		int K = 1;
		for (int i = 0; i < A.size() && K < N; ++i)
		{
			int V = A[i] % 1000;
			int U = A[i] / 1000 % 1000;
			if (!uf.find(U, V))
			{
				uf.unite(U, V);
				result += A[i] / 1'000'000;
				++K;
			}
		}
		return result;
	}
};