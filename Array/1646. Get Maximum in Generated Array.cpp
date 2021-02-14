class Solution {
public:
	int getMaximumGenerated(int n) {
		vector<int> A(n + 1);
		A[0] = 0;
        if (n > 0)
            A[1] = 1;
		for (int x = 2; x <= n; ++x)
		{
			int i = x / 2;
			if (x % 2 == 0)
				A[x] = A[i];
			else
				A[x] = A[i] + A[i + 1];
		}
		return *max_element(A.begin(), A.end());
	}
};