class Solution {
public:
	vector<int> prevPermOpt1(vector<int>& A) {
		vector<int> result(A), M(A);
		for (int i = A.size() - 2; i >= 0; --i)
			M[i] = min(M[i], M[i + 1]);
		int x = -1;
		for (int i = 0; i + 1 < A.size(); ++i)
			if (A[i] > M[i])
				x = i;
		if (x != -1)
		{
			int y = -1;
			for(int i = A.size() - 1; i >= 0; --i)
				if (A[i] < A[x])
				{
					y = i;
					break;
				}
			swap(result[x], result[y]);
		}
		return result;
	}
};