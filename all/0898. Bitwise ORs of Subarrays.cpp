class Solution {
public:
	int subarrayBitwiseORs(vector<int>& A) {
		unordered_set<int> S;
		vector<int> M(A);
		for (int a = 0; a < A.size(); ++a)
		{
			int x = A[a];
			S.insert(x);
			for (int b = a; b < A.size(); ++b)
			{
				x |= A[b];
				S.insert(x);
				if (a && x == M[b])
					break;
				M[b] = x;
			}
		}
		return S.size();
	}
};