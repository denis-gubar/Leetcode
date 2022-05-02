class Solution {
public:
	int calc(vector<int> const& A)
	{
		int result = A.size() - lengthOfLIS(A);
		return result;
	}
	int lengthOfLIS(vector<int> const& nums) {
		vector<int> M;
		for (int n : nums)
		{
			auto it = lower_bound(M.begin(), M.end(), n + 1);
			if (it == M.end())
				M.push_back(n);
			else
				*it = n;
		}
		return M.size();
	}
	int kIncreasing(vector<int>& arr, int k) {
		int result = 0;
		int N = arr.size();
		vector<int> A;
		for (int i = 0; i < k; ++i)		
		{
			A.clear();
			for (int j = i; j < N; j += k)
				A.push_back(arr[j]);
			result += calc(A);
		}
		return result;
	}
};