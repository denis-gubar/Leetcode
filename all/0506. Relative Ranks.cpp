class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		int N = nums.size();
		vector<pair<int, int>> A(N);
		for (int i = 0; i < N; ++i)
			A[i] = { -nums[i], i };
		sort(A.begin(), A.end());
		vector<string> result(N);
		for (int i = 0; i < N; ++i)
			if (i == 0)
				result[A[i].second] = "Gold Medal";
			else if (i == 1)
				result[A[i].second] = "Silver Medal";
			else if (i == 2)
				result[A[i].second] = "Bronze Medal";
			else
				result[A[i].second] = to_string(i + 1);
		return result;
	}
};