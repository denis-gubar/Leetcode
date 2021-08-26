class Solution {
public:
	int longestMountain(vector<int>& A) {
		int result = 0;
		A.insert(A.begin(), 1000000);
		int N = A.size();
		int a = 1, b = 1;
		bool isMount = false;
		while (b < N)
		{
			if (A[b] < A[b - 1])
			{
				if (!isMount)
					if (a < b - 1)
						isMount = true;
					else
						a = b;
			}
			else if (A[b] == A[b - 1])
			{
				isMount = false;
				a = b;
			}
			else
			{
				if (isMount)
				{
					isMount = false;
					a = b - 1;
				}
			}
			if (isMount)
				result = max(result, b - a + 1);
			++b;
		}
		return result;
	}
};