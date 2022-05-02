class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> result;
		vector<long long> A(nums.begin(), nums.end());
		A.insert(A.begin(), lower - 1LL);
		A.push_back(upper + 1LL);
		for (int i = 0; i + 1 < A.size(); ++i)
			if (A[i + 1] - A[i] == 2)
				result.push_back(to_string(A[i] + 1));
			else if (A[i + 1] - A[i] > 2)
				result.push_back(to_string(A[i] + 1) + "->" + to_string(A[i + 1] - 1));
		return result;
	}
};