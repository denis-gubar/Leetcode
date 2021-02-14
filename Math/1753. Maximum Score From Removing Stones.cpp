class Solution {
public:
	int maximumScore(int a, int b, int c) {
		int result = 0;
		vector<int> A{ a, b, c };
		while (true)
		{
			sort(A.begin(), A.end());
			if (A[0] == 0)
			{
				if (A[1] == 0)
					break;
				--A[1];
				--A[2];
				++result;
			}
			else
			{
				--A[0];
				--A[2];
				++result;
			}
		}
		return result;
	}
};