class Solution {
public:
	int binaryGap(int N) {
		int result = 0;
		vector<int> A;
		while (N)
		{
			A.push_back(N % 2);
			N /= 2;
		}
		int start = -1, end = -1;
		for(int i = 0; i < A.size(); ++i)
			if (A[i])
			{
				start = end;
				end = i;
				if (start >= 0)
					result = max(result, end - start);
			}
		return result;
	}
};