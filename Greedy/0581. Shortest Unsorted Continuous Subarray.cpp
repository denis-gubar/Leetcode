class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		if (is_sorted(nums.begin(), nums.end())) return 0;
		int N = nums.size();
		int result = N;
		vector<int>	A(nums);
		sort(A.begin(), A.end());
		for (int i = 0; A[i] == nums[i]; ++i)
			--result;
		for (int i = N - 1; A[i] == nums[i]; --i)
			--result;
		return result;
	}
};