class Solution {
public:
	int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
		long long result = 1LL << 60;
		int N = packages.size(), M = boxes.size();
		for (vector<int>& A : boxes)
			sort(A.begin(), A.end());
		sort(packages.begin(), packages.end());
		vector<long long> P(N + 1);
		for (int i = 0; i < N; ++i)
			P[i + 1] = P[i] + packages[i];
		for (int i = 0; i < M; ++i)
		{
			long long total = 0;
			auto it = packages.begin();
			for (int x : boxes[i])
			{
				if (it == packages.end())
					break;
				auto next_it = upper_bound(it, packages.end(), x);
				long long length = next_it - it;
				int L = it - packages.begin();
				int R = next_it - packages.begin();
				total += length * x - (P[R] - P[L]);
                it = next_it;
			}
			if (it == packages.end())
				result = min(result, total);
		}
		if (result == 1LL << 60)
			result = -1;
		return result % 1'000'000'007;
	}
};