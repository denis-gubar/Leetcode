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
	vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
		vector<vector<int>> result(2);
		UnionFind uf(n);
		vector<int>	A(edges.size());
		iota(A.begin(), A.end(), 0);
		sort(A.begin(), A.end(), [&edges](int a, int b)
			{
				return edges[a][2] < edges[b][2];
			});
		int total = 0;
		for (int i = 0, x = n - 1; x > 0 && i < edges.size(); ++i)
			if (!uf.find(edges[A[i]][0], edges[A[i]][1]))
			{
				--x;
				total += edges[A[i]][2];
				uf.unite(edges[A[i]][0], edges[A[i]][1]);
			}
		for (int z = 0; z < edges.size(); ++z)
		{
			UnionFind uf(n);
			int sum = 0;
            int x = n - 1;
			for (int i = 0; x > 0 && i < edges.size(); ++i)
				if (i != z && !uf.find(edges[A[i]][0], edges[A[i]][1]))
				{
					--x;
					sum += edges[A[i]][2];
					uf.unite(edges[A[i]][0], edges[A[i]][1]);
				}
			if (x > 0 || sum > total)
				result[0].push_back(A[z]);
		}
		for (int z = 0; z < edges.size(); ++z)
		{
			UnionFind uf(n);
			int sum = 0, x = n - 2;
			sum += edges[A[z]][2];
			uf.unite(edges[A[z]][0], edges[A[z]][1]);
			for (int i = 0; x > 0 && i < edges.size(); ++i)
				if (i != z && !uf.find(edges[A[i]][0], edges[A[i]][1]))
				{
					--x;
					sum += edges[A[i]][2];
					uf.unite(edges[A[i]][0], edges[A[i]][1]);
				}  
			if (x == 0 && sum == total)
				result[1].push_back(A[z]);
		}
		sort(result[0].begin(), result[0].end());
		sort(result[1].begin(), result[1].end());
		vector<int>	B;
		set_difference(result[1].begin(), result[1].end(), result[0].begin(), result[0].end(), back_inserter(B));
		result[1] = move(B);
		return result;
	}
};