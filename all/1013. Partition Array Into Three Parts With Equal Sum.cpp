class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		int total = accumulate(A.begin(), A.end(), 0);
		if (total % 3 != 0)
			return false;
		int sum = 0, a = 0, b = A.size() - 1;
		for (; a < A.size(); ++a)
		{
			sum += A[a];
			if (sum * 3 == total)
				break;
		}
		sum = 0;
		for (; b > 0; --b)
		{
			sum += A[b];
			if (sum * 3 == total)
				break;
		}
		return a < b;
	}
};