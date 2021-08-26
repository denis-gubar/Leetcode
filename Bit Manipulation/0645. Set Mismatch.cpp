class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<bool> A(nums.size() + 1);
		int sum = 0;
		int first = -1;
		for (int n : nums)
		{
			if (!A[n])
				A[n] = true;
			else
				first = n;
			sum += n;
		}
		int N = nums.size();
		int delta = N * (N + 1) / 2 - sum;
		return { first, first + delta };
	}
};