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
	int minSumOfLengths(vector<int>& arr, int target) {
		int a = 0, b = 0, sum = 0;
		vector<pair<int, int>> L;
		int N = arr.size();
		while (b < N)
		{
			while (b < N && sum + arr[b] < target)
				sum += arr[b], ++b;
			if (b < N)
				sum += arr[b], ++b;
			if (sum == target)
				L.emplace_back(b - a, a);
			while (sum - arr[a] > target)
				sum -= arr[a], ++a;
			sum -= arr[a], ++a;
			if (sum == target)
				L.emplace_back(b - a, a);
		}
		sort(L.begin(), L.end());
		if (L.size() < 2)
			return -1;
		int result = 1'000'000'000;
		for (int k = 0; k < L.size() && k < 5; ++k)
		{
			int fa = L[k].second, fb = fa + L[k].first - 1, fl = L[k].first;
			for (int i = k + 1; i < L.size(); ++i)
			{
				int ia = L[i].second, ib = ia + L[i].first - 1, il = L[i].first;
				if ((fa > ib || fb < ia) && result > fl + il)
					result = fl + il;
			}
			if (result == 1'000'000'000)
				return -1;
		}		
		return result;
	}
};