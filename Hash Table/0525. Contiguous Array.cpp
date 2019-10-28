class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int result = 0;        
		int N = nums.size();
        if (!N)
            return result;
		vector<int> A(N);
		A[0] = nums[0] * 2 - 1;
		for (int i = 1; i < N; ++i)
			A[i] = A[i - 1] + nums[i] * 2 - 1;
		unordered_map<int, int> M;
		M[0] = -1;
		for (int i = 0; i < N; ++i)
			if (M.find(A[i]) == M.end())
				M[A[i]] = i;
			else
				result = max(result, i - M[A[i]]);
		return result;
	}
};