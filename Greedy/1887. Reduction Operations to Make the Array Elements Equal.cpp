class Solution {
public:
	int reductionOperations(vector<int>& nums) {
		int result = 0;
		int N = nums.size(); 
		vector<int> A(nums);
		sort(A.begin(), A.end());
		A.resize(unique(A.begin(), A.end()) - A.begin());
		vector<int> ind(50'001);
		for (int i = 0; i < A.size(); ++i)
			ind[A[i]] = i;
		for (int x : nums)
			result += ind[x];
		return result;
	}
};