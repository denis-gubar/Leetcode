class Solution {
public:
	vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
		vector<bool> result;
		int N = candiesCount.size();
		vector<long long> A{ 0LL };
		for (int i = 0; i < N; ++i)
			A.push_back(A.back() + candiesCount[i]);
		A.push_back(1'000'000'000'000'000LL);
		for (vector<int> const& Q : queries)
		{
			int const& type = Q[0];
			int const& day = Q[1];
			int const& cap = Q[2];
			long long a = day;
			long long b = cap * (a + 1);
			int x = lower_bound(A.begin(), A.end(), a + 1) - A.begin() - 1;
			int y = lower_bound(A.begin(), A.end(), b) - A.begin() - 1;
			bool flag = x <= type && type <= y;
			result.push_back(flag);
		}
		return result;
	}
};