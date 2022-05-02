class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		for (int i = 1; i + 1 < A.size(); ++i)
			if (A[i - 1] < A[i] && A[i] > A[i + 1])
				return i;
		return -1;
	}
};