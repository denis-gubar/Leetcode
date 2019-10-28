class Solution {
public:
	const int MOD = 1'000'000'007;
	int numRollsToTarget(int d, int f, int target) {
		vector<int> M(target + 1);
		M[0] = 1;
		for (int k = 0; k < d; ++k)
		{
			vector<int> result(target + 1);
			for (int i = target; i > 0; --i)
				for (int j = min(f, i); j >= 1; --j)
				{
					result[i] += M[i - j];
					result[i] %= MOD;
				}
            M.swap(result);
        }
		return M[target];
	}
};