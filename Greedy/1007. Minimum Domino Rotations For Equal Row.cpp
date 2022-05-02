class Solution {
public:
	int minDominoRotations(vector<int>& A, vector<int>& B) {
		int N = A.size();
		int INF = N + 1;
		int result = INF;
		set<int> S;
		S.insert(A[0]);
		S.insert(B[0]);
		for (int pos = 0; pos < 2; ++pos)
		{
			vector<int>* a = &A;
			vector<int>* b = &B;
			if (pos)
				a = &B, b = &A;
			for (int x : S)
			{
				int current = 0;
				for (int i = 0; i < N; ++i)
					if ((*a)[i] != x)
					{
						if ((*b)[i] == x)
							++current;
						else
						{
							current = INF;
							break;
						}
					}
				result = min(result, current);
			}
		}
		if (result == INF)
			result = -1;
		return result;
	}
};