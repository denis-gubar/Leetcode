class Solution {
public:
	static const int MOD = 1000000007;
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
		long long result = 0;
		vector<pair<int, int>> pairs(n);
		for (int i = 0; i < n; ++i)
			pairs[i] = { efficiency[i], speed[i] };
		sort(pairs.begin(), pairs.end());
		vector<int> distinctEfficiency(efficiency.begin(), efficiency.end());
		sort(distinctEfficiency.begin(), distinctEfficiency.end());
		distinctEfficiency.erase(unique(distinctEfficiency.begin(), distinctEfficiency.end()), distinctEfficiency.end());
		auto calc = [&pairs, &distinctEfficiency, k](int eff)
		{
			auto it = lower_bound(pairs.begin(), pairs.end(), pair<int, int>{ distinctEfficiency[eff], 0 });
			vector<pair<int, int>> part(it, pairs.end());
			if (part.size() > k)
				sort(part.begin(), part.end(),
					[](pair<int, int> a, pair<int, int> b)
					{
						return a.second > b.second;
					});
			long long sum = 0;
			for (int i = 0; i < k && i < part.size(); ++i)
				sum += part[i].second;
			return sum * distinctEfficiency[eff];
		};
		int N = distinctEfficiency.size();
		int a = 0, b = N - 1;
		long long A = calc(a);
		result = max(result, A);
		long long B = calc(b);
		result = max(result, B);
		while (b - a > 2500)
		{
			int delta = (b - a) / 3;
            if (delta == 0) ++delta;
			int c = a + delta;
			int d = b - delta;
			long long C = calc(c);
			result = max(result, C);
			long long D = calc(d);
			result = max(result, D);
			if (C == D)
			{
				A = C, B = D;
				a = c, b = d;
			}
			else if (C < D)
				A = C, a = c;
			else
				B = D, b = d;
		}
        for(int x = a + 1; x < b; ++x)
            result = max(result, calc(x));
		return result % MOD;
	}
};