class Solution {
public:
	vector<int> LIS(vector<int> const& nums) {
		vector<int> result;
		vector<int> M;
		for (int n : nums)
		{
			auto it = upper_bound(M.begin(), M.end(), n - 1);
            int x = distance(M.begin(), it);
			if (it == M.end())
				M.push_back(n);
			else
				*it = n;
			result.push_back(x);
		}
		return result;
	}
	int minimumMountainRemovals(vector<int> const& nums) {
		vector<int> left = LIS(nums);
		vector<int> R(nums);
		reverse(R.begin(), R.end());
		vector<int> right = LIS(R);
		reverse(right.begin(), right.end());
        int N = nums.size();
		int result = N - 3;
		for (int i = 0; i < N; ++i)
			if (left[i] > 0 && right[i] > 0)
				result = min(result, N - 1 - left[i] - right[i]);
		return result;
	}
};