class Solution {
public:
	bool canMakeArithmeticProgression(vector<int>& A) {
		int N = A.size();
    sort(A.begin(), A.end());
		for (int i = 2; i < N; ++i)
			if (A[i] - A[i - 1] != A[1] - A[0])
                return false;
		return true;
	}
};