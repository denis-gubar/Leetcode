class Solution {
public:
	int minMoves(vector<int>& nums, int limit) {
		int N = nums.size();
		int result = N;
		vector<int> F(2 * limit + 1), A(2 * limit + 2);
		A[0] = N;
		for (int i = 0; i < N / 2; ++i)
		{
			int x = nums[i], y = nums[N - i - 1];
			++F[x + y];
			--A[min(x, y) + 1];
			++A[max(x, y) + limit + 1];
		}
		int current = 0;
		for (int i = 0; i <= 2 * limit; ++i)
		{
			current += A[i];
			current -= F[i];
			result = min(result, current);
			current += F[i];
		}
		return result;
	}
};