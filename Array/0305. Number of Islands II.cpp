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
	vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
		vector<int>	result;
		int current = 0;
		int k = positions.size();
		UnionFind unionFind(k);
		map<vector<int>, int> lands;
		vector<int>	dx{ 0, 1, 0, -1 };
		vector<int>	dy{ 1, 0, -1, 0 };
		for (int i = 0; i < k; ++i)
		{
			++current;
            if (lands.find(positions[i]) != lands.end())
            {
                --current;
                result.push_back(current);
                continue;
            }
			lands[positions[i]] = i;
			int const& x = positions[i][0];
			int const& y = positions[i][1];
			for (int z = 0; z < 4; ++z)
			{
				int nx = x + dx[z];
				int ny = y + dy[z];
				auto it = lands.find({ nx, ny });
				if (it != lands.end() && !unionFind.find(it->second, i))
				{
					unionFind.unite(it->second, i);
					--current;
				}
			}
			result.push_back(current);
		}
		return result;
	}
};