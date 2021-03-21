class Solution {
public:
	template<typename T> T gcd(T a, T b)
	{
		while (a && b) if (a > b) a %= b; else b %= a; return a + b;
	}
	void calc(vector<int>& nums, int mask, int i)
	{
		if (i > N)
			return;
		for (int a = 0; a < N; ++a)
			if ((mask & (1 << a)) == 0)
				for (int b = a + 1; b < N; ++b)
					if ((mask & (1 << b)) == 0)
					{
						int newMask = mask | (1 << a) | (1 << b);
						if (F[newMask] < F[mask] + i * G[a][b])
						{
							F[newMask] = F[mask] + i * G[a][b];
							calc(nums, newMask, i + 1);
						}
					}
	}
	int N;
	int maxScore(vector<int>& nums) {
		int result = 0;
		N = nums.size();
		G = vector<vector<int>>(N, vector<int>(N));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				G[i][j] = gcd(nums[i], nums[j]);
		F = vector<int>(1 << N);
		calc(nums, 0, 1);
		return F.back();
	}
	vector<vector<int>> G;
	vector<int> F;
};