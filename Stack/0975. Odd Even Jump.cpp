class Solution {
public:
	template<typename T>
	void mergeSort(vector<pair<int, int>>& A, vector<int> const& original, vector<int>& result, T const& comp)
	{
		int N = A.size();
		if (N < 2) return;
		int m = N / 2;
		vector<pair<int, int>> L(A.begin(), A.begin() + m);
		vector<pair<int, int>> R(A.begin() + m, A.end());
		mergeSort(L, original, result, comp);
		mergeSort(R, original, result, comp);
		auto left = L.begin();
		auto right = R.begin();
		stack<int> S;
		for (int i = 0; i < N; ++i)
		{
			if (right == R.end() || left != L.end() && comp(*left, *right))
			{
				A[i] = *left;
				S.push(left->second);
				++left;
			}
			else
			{
				A[i] = *right;
				while (!S.empty())
				{
					int pos = S.top(); S.pop();
					int& v = result[pos];
					if (v == -1 || comp(*right, { original[v], v }))
						v = right->second;
				}
				++right;
			}
		}
	}
	int calc(int x, int step, vector<vector<int>>& F, vector<vector<int>> const& next)
	{
		if (x == -1)
			return 0;
		if (x + 1 == F[0].size())
			return 1;
		if (F[step][x] < 0)
			F[step][x] = calc(next[step][x], 1 - step, F, next);
		return F[step][x];
	}
	int oddEvenJumps(vector<int>& A) {
		int result = 0;
		int N = A.size();
		vector<pair<int, int>> P(N);
		for (int i = 0; i < N; ++i)
			P[i] = { A[i], i };
		vector<vector<int>> next(2, vector<int>(N, -1));
		mergeSort(P, A, next[0], less<pair<int, int>>());
		for (int i = 0; i < N; ++i)
			P[i] = { A[i], i };
		mergeSort(P, A, next[1], [](pair<int, int> a, pair<int, int> b)
			{
				if (a.first != b.first)
					return a.first > b.first;
				return a.second < b.second;
			});
		vector<vector<int>> F(2, vector<int>(N, -1));
		for (int i = 0; i < N; ++i)
			result += calc(i, 0, F, next);
		return result;
	}
};