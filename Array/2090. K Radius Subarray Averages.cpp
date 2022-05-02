class Solution {
public:
	vector<int> getAverages(vector<int>& nums, int k) {
		int N = nums.size();
		vector<int> result(N, -1);
		long long sum = 0;
		for (int i = 0; i < N && i < 2 * k + 1; ++i)
			sum += nums[i];
		for (int i = k; i + k < N; ++i)
		{
			result[i] = sum / (2 * k + 1);
			sum -= nums[i - k];
			if (i + k + 1 < N)
				sum += nums[i + k + 1];
		}
		return result;
	}
};