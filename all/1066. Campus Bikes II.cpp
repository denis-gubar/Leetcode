class Solution {
public:
	int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
		int W = workers.size(), B = bikes.size();
        int result = 1 << 20;
		vector<int> F(1 << B, 1 << 20);
		vector<unordered_set<int>> S(2);
		auto distance = [&workers, &bikes](int i, int k)
		{
			return abs(workers[i][0] - bikes[k][0]) + abs(workers[i][1] - bikes[k][1]);
		};
		F[0] = 0;
		S[0].insert(0);
		for (int i = 0; i < W; ++i)
		{
			S[(i + 1) % 2].clear();
			for(int mask : S[i % 2])
				for(int k = 0; k < B; ++k)
					if ((mask & (1 << k)) == 0)
					{
						int newMask = mask | (1 << k);
						if (F[newMask] > F[mask] + distance(i, k))
						{
							F[newMask] = F[mask] + distance(i, k);
                            if (i == W - 1)                            
                                result = min(result, F[newMask]);
                            else
							    S[(i + 1) % 2].insert(newMask);
						}
					}
		}
		return result;
	}
};