class Solution {
public:
	int minTaps(int n, vector<int>& ranges) {		
		vector<int> F(n + 1, 100'000), L(n + 1, -100'000);
		F[0] = 0; L[0] = -1;
		for(int i = 0; i < n + 1; ++i)
			for(int x = L[i] + 1; x >= 0 && x <= min(n, i + 101); ++x)
				if (x - ranges[x] <= i && x + ranges[x] >= i + 1)
				{
					int nx = min(n, x + ranges[x]);
					if (F[nx] > F[i] + 1)
					{
						F[nx] = F[i] + 1;
						L[nx] = x;
					}
				}
		int result = F[n];
		if (result > 10'000)
			result = -1;
		return result;
	}
};