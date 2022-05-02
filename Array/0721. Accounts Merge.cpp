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
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		vector<vector<string>> result;
		int N = accounts.size();
		for (int i = 0; i < N; ++i)
			sort(accounts[i].begin() + 1, accounts[i].end());
		UnionFind uf(N);
		sort(accounts.begin(), accounts.end());
		for (int i = 0; i < N; ++i)
		{
			int j = i;
			while (j + 1 < N && accounts[i][0] == accounts[j + 1][0])
				++j;
			unordered_map<string, vector<int>> M;
			for (int k = i; k <= j; ++k)
				for (int z = 1; z < accounts[k].size(); ++z)
					M[accounts[k][z]].push_back(k);
			for (auto& [key, value] : M)
				for (int z : value)
					uf.checkedUnite(value[0], z);
			i = j;
		}
		vector<set<string>> V(N);
		for (int i = 0; i < N; ++i)
			for (int z = 1; z < accounts[i].size(); ++z)
				V[uf.root(i)].insert(accounts[i][z]);
		for (int i = 0; i < N; ++i)
			if (!V[i].empty())
            {
				result.push_back({ accounts[i][0] });
                result.back().insert(result.back().end(), V[i].begin(), V[i].end());
            }
		return result;
	}
};