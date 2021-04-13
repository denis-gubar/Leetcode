class Solution {
public:
	int findTheWinner(int n, int k) {
		vector<int>	A(n);
		iota(A.begin(), A.end(), 1);
		int pos = 0;
		while (A.size() > 1)
		{
			pos = (pos + k - 1) % A.size();
			A.erase(A.begin() + pos);
		}
		return A[0];
	}
};