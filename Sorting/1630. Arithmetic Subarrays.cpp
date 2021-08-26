class Solution {
public:
	vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
		int N = nums.size();
		int M = l.size();
		vector<bool> result(M);
		for (int i = 0; i < M; ++i)
		{
			result[i] = false;
			vector<int> A(nums.begin() + l[i], nums.begin() + r[i] + 1);
			sort(A.begin(), A.end());
			if (A.size() > 1)
			{
				result[i] = true;
				for (int j = 2; j < A.size(); ++j)
					if (A[j] - A[j - 1] != A[1] - A[0])
					{
						result[i] = false;
						break;
					}
			}
		}
		return result;
	}
};