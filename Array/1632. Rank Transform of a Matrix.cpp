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
	vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
		int N = matrix.size(), M = matrix[0].size();
		vector<vector<int>> result(N, vector<int>(M));
		vector<pair<int, pair<int, int>>> A;
		int const NA = 1 << 30;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				A.push_back({ matrix[i][j], {i, j} });
		sort(A.begin(), A.end());
		vector<pair<int, int>> row(N, { NA, 0 }), col(M, { NA, 0 });
		for (int k = 0, rank = 0; k < A.size(); ++k)
		{
			int z = k;
			int value = A[k].first;
			while (z + 1 < A.size() && A[z + 1].first == A[z].first)
				++z;
			int groupSize = z - k + 1;
			UnionFind uf(groupSize);
			for (int i = k + 1; i <= z; ++i)
				if (A[i - 1].second.first == A[i].second.first)
					uf.checkedUnite(i - k, i - k - 1);
			vector<pair<int, int>> B;
			B.reserve(groupSize);
			for (int i = k; i <= z; ++i)
				B.emplace_back(A[i].second.second, i - k);
			sort(B.begin(), B.end());
			for (int i = 1; i < groupSize; ++i)
				if (B[i - 1].first == B[i].first)
					uf.checkedUnite(B[i - 1].second, B[i].second);
			unordered_map<int, int> current;
			for (int t = k; t <= z; ++t)
			{
				int const& x = A[t].second.first;
				int const& y = A[t].second.second;
				int root = uf.root(t - k);
				if (row[x].first != value)
					row[x] = { value, row[x].second + 1 };
				if (col[y].first != value)
					col[y] = { value, col[y].second + 1 };
				current[root] = max(current[root], max(row[x].second, col[y].second));
			}
			for (int t = k; t <= z; ++t)
			{
				int const& x = A[t].second.first;
				int const& y = A[t].second.second;
				int root = uf.root(t - k);
				row[x].second = col[y].second = result[x][y] = current[root];
			}
			k = z;
		}
		return result;
	}
};