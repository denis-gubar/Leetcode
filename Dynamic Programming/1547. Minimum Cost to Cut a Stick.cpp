class Solution {
public:
	int calc(int a, int b, vector<int>& cuts)
	{
		short hash = a * 105 + b;
		if (M.find(hash) == M.end())
		{
			if (a + 1 == b) return M[hash] = 0;
			int result = 1 << 28;
			for(int mid = a + 1; mid < b; ++mid)
				result = min(result, cuts[b] - cuts[a] + calc(a, mid, cuts) + calc(mid, b, cuts));
			M[hash] = result;
		}
		return M[hash];
	}
	unordered_map<short, int> M;
	int minCost(int n, vector<int>& cuts) {
		int N = cuts.size();
		M.clear();
		cuts.push_back(0);
		cuts.push_back(n);
		sort(cuts.begin(), cuts.end());		
		return calc(0, N + 1, cuts);
	}
};