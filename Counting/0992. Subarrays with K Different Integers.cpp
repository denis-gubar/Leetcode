class Solution {
public:
	int subarraysWithKDistinct(vector<int>& A, int K) {
		int result = 0;
		int a = 0, b = 0, distinct = 0;
		vector<int> counts(A.size() + 1);
		while (a < A.size())
		{
			if (a && --counts[A[a - 1]] == 0)
				--distinct;
			if (distinct == K)
			{
				while (b >= a && distinct == K)
				{
					if (--counts[A[b]] == 0)
						--distinct;
					--b;
				}
			}
			if (a)
				++b;
			while (distinct <= K && b < A.size())
			{
				if (++counts[A[b]] == 1)
					++distinct;
				if (distinct == K)
					++result;
				++b;
			}
			--b;
			if (distinct > K)
				--counts[A[b]], --distinct, --b;
			if (distinct < K)
				break;
			++a;
		}
		return result;
	}
};