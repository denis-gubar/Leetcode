class Solution {
public:
	using Iter = vector<int>::iterator;
	int calc(int a, int b, Iter first, Iter last, unordered_map<long long, int>& M)
	{
		long long hash = a * 1'000'000LL + b;
		if (M.find(hash) == M.end())
		{
			if (first == last) return M[hash] = 0;
			Iter mid = first;
			int result = b - a + calc(a, *mid, first, mid, M) + calc(*mid, b, mid + 1, last, M);
			++mid;
			while (mid != last)
			{
				result = min(result, b - a + calc(a, *mid, first, mid, M) + calc(*mid, b, mid + 1, last, M));
				++mid;
			}
			M[hash] = result;
		}
		return M[hash];
	}
	int minCost(int n, vector<int>& cuts) {
		sort(cuts.begin(), cuts.end());
		unordered_map<long long, int> M;
		return calc(0, n, cuts.begin(), cuts.end(), M);
	}
};