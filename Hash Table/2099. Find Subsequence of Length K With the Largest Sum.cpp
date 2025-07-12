class Solution {
public:
	vector<int> maxSubsequence(vector<int>& nums, int k) {
		vector<int> result;
		int N = nums.size();
		vector<pair<int, int>> A;
		for (int i = 0; i < N; ++i)
			A.push_back({ nums[i], i });
		sort(A.begin(), A.end());
		vector<int>	I;
        I.reserve(k);
		for (int i = N - k; i < N; ++i)
			I.push_back(A[i].second);
		sort(I.begin(), I.end());
		for (int x : I)
			result.push_back(nums[x]);
		return result;
	}
};