class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int result = 0, N = A.size();
		int a = 0, b = 0, count0 = 0;
		while (b < N)
		{
			if (A[b] == 0)
			{
				if (count0 == K)
				{
					while(A[a] == 1)
						++a;
                    ++a;
				}
				else
					++count0;
			}
			result = max(result, b - a + 1);
			++b;
		}
		return result;
	}
};