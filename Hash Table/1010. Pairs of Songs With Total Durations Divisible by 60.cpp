class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		int result = 0, N = time.size();
		vector<int> A(60);
		for (int i = 0; i < N; ++i)
		{
			result += A[(60000 - time[i]) % 60];
			++A[time[i] % 60];
		}
		return result;
	}
};