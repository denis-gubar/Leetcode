class Solution {
public:
	bool check(vector<int> const& A, int m, int k, int day)
	{
		int b = 0, count = 0, total = 0;
		while (b < A.size())
		{
			if (A[b] <= day)
				++count;
			else
				count = 0;
			if (count == k)
				count = 0, ++total;
			if (total == m)
				return true;
			++b;
		}
		return false;
	}
	int minDays(vector<int>& bloomDay, int m, int k) {
		int N = bloomDay.size();
		if (m * k > N)
			return -1;
		int INF = 1'000'000'001;
		vector<int>	A(bloomDay);
		sort(A.begin(), A.end());
		A.resize(unique(A.begin(), A.end()) - A.begin());
		int a = -1, b = A.size() - 1;
		while (a + 1 < b)
		{
			int M = (b + a) / 2;
			if (check(bloomDay, m, k, A[M]))
				b = M;
			else
				a = M;
		}
		return A[b];
	}
};