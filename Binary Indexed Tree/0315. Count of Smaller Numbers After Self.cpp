class Solution {
public:
	void mergeSort(vector<pair<int, int>>& A, vector<int>& result)
	{
		int N = A.size();
		if (N < 2) return;
		int m = N / 2;
		vector<pair<int, int>> left(A.begin(), A.begin() + m);
		vector<pair<int, int>>	right(A.begin() + m, A.end());
		mergeSort(left, result);
		mergeSort(right, result);
		auto L = left.begin();
		auto R = right.begin();
		for (int i = 0; i < N; ++i)
		{
			if (R == right.end() || L != left.end() && L->first <= R->first)
			{
				result[L->second] += R - right.begin();
				A[i] = *L, ++L;
			}
			else
			{
				A[i] = *R, ++R;
			}
		}
	}
	vector<int> countSmaller(vector<int>& nums) {		
		int N = nums.size();
		vector<pair<int, int>> A;
		for (int i = 0; i < N; ++i)
			A.emplace_back(nums[i], i);
		vector<int>	result(N);
		mergeSort(A, result);
		return result;
	}
};