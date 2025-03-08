class Solution {
public:
	int maxAbsoluteSum(vector<int>& nums) {
		int result = 0;
        int const N = nums.size();
		vector<int>	A{ 0 };
        A.reserve(N + 1);
		partial_sum(nums.begin(), nums.end(), back_inserter(A));
		int a = *max_element(A.begin(), A.end());
		int b = *min_element(A.begin(), A.end());
		result = max({ result, abs(a), abs(b), abs(a - b) });
		return result;
	}
};