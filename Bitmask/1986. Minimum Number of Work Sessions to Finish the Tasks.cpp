class Solution {
public:
	int minSessions(vector<int>& tasks, int sessionTime) {
		int N = tasks.size();
		vector<bool> goodMask(1 << N);
		for (int mask = 0; mask < (1 << N); ++mask)
		{
			int sum = 0;
			for (int k = 0; k < N; ++k)
				if (mask & (1 << k))
					sum += tasks[k];
			if (sum <= sessionTime)
				goodMask[mask] = true;
		}
		vector<int>	F(1 << N, 100);
		F[0] = 0;
		queue<int> Q;
		Q.push(0);
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			int mask = ((1 << N) - 1) ^ x;
			int nextMask = mask;
			while (nextMask > 0)
			{
				if (goodMask[nextMask] && F[nextMask | x] > F[x] + 1)
				{
					F[nextMask | x] = F[x] + 1;
					Q.push(nextMask | x);
				}
				nextMask = (nextMask - 1) & mask;
			}
		}
		return F.back();
	}
};