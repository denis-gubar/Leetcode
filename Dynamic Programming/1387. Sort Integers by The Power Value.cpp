class Solution {
public:
	int calc(int x)
	{
		int result = 0;
		while (x != 1)
		{
			if (x % 2 == 0) x /= 2;
			else x = 3 * x + 1;
			++result;
		}
		return result;
	}
	int getKth(int lo, int hi, int k) {
		vector<pair<int, int>> A;
		for (int i = lo; i <= hi; ++i)
			A.emplace_back(calc(i), i);
		sort(A.begin(), A.end());
		return A[k - 1].second;
	}
};