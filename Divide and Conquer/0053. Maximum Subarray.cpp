class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int result = *max_element(nums.begin(), nums.end());
		vector<int> A(nums.size() + 1);
        partial_sum(nums.begin(), nums.end(), A.begin() + 1);
		int current = A[0];
		for (int a : A)
			if (current < a)
				result = max(result, a - current);
			else
				current = a;
		return result;
	}
};