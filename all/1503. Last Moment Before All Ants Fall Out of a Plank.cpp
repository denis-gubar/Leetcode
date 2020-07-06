class Solution {
public:
    void print(bitset<10'002> A, int n, string label)
	{
		cout << label << ": ";
		for (int i = 0; i <= n; ++i)
			cout << A[i];
		cout << '\n';
	}
	int getLastMoment(int n, vector<int>& left, vector<int>& right) {
		int result = 0;
		bitset<10'002> L, R, Zero, Mask;
		for (int x : left)
			L[x] = 1;
		for (int x : right)
			R[x] = 1;
		for (int x = 0; x <= n; ++x)
			Mask[x] = 1;
		while (true)
		{
			if (L == Zero && R == Zero)
				return result - 1;
			L >>= 1;
			R <<= 1;
			L[n + 1] = R[n + 1] = 0;
			++result;
		}
		return result;
	}
};