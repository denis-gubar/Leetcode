class Solution {
public:
	int longestArithSeqLength(vector<int>& A) {
		int result = 2;
		vector<vector<int>> M(10001);
		for (int i = 0; i < A.size(); ++i)
			M[A[i]].push_back(i);
		for(int a = 0; a < A.size(); ++a)
			for (int B = a + 1; B < A.size(); ++B)
			{
				int b = B;
				int delta = A[b] - A[a];
				int k = 2;
				while (A[b] + delta >= 0 && A[b] + delta <= 10000 &&
					!M[A[b] + delta].empty())
				{
					int x = A[b] + delta;
					auto it = upper_bound(M[x].begin(), M[x].end(), b);
					if (it != M[x].end())
					{
						++k; b = *it;
						result = max(result, k);
					}
					else
						break;
				}				
			}
		return result;
	}
};