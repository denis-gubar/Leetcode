class Solution {
public:
	vector<int> advantageCount(vector<int>& A, vector<int>& B) {
		int N = B.size();
		vector<int> result(N, -1);
		set<pair<int, int>> S;
		for (int i = 0; i < N; ++i)
			S.insert(pair<int, int>{ B[i], i });
		sort(A.begin(), A.end());
		auto it = S.begin();
		for (int i = 0; i < N; ++i)
		{
			if (A[i] > it->first)
			{
				result[it->second] = A[i];
				++it;
				A[i] = -1;
			}
		}
		int pos = 0;
		for (int i = 0; i < N; ++i)
		{
			if (A[i] >= 0)
			{
				while (result[pos] >= 0)
					++pos;
				result[pos] = A[i];
				++pos;
			}
		}
		return result;
	}
};