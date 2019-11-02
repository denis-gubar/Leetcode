class Solution {
public:
	vector<int> transformArray(vector<int>& arr) {
		vector<int> A(arr);
		while(true)
		{
			vector<int> B(A);
			for (int i = 1; i + 1 < B.size(); ++i)
				if (A[i - 1] > A[i] && A[i + 1] > A[i])
					++B[i];
				else if (A[i - 1] < A[i] && A[i + 1] < A[i])
					--B[i];
			if (A == B)
				return A;
			A = move(B);
		}
		return {};
	}
};