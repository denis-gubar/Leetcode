class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int N = A.size();
		int a = 0, b = N;
		while(a + 1 < b)
		{
			int m = (a + b) / 2;
			if (A[m] < A[m + 1])
				a = m;
			else
				b = m;
		}
		return b;
	}
};