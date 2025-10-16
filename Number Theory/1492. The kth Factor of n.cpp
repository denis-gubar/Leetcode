class Solution {
public:
	int kthFactor(int n, int k) {
		vector<int>	A;
		for (int x = 1; x <= n; ++x)
			if (n % x == 0)
				A.push_back(x);
		if (A.size() < k)
			return -1;
		return A[k - 1];
	}
};