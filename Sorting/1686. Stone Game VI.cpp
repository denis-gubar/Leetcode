class Solution {
public:
	int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
		int N = aliceValues.size();
		vector<pair<int, int>> A(N);
		for (int i = 0; i < N; ++i)
			A.push_back({-aliceValues[i] - bobValues[i], i});
		sort(A.begin(), A.end());
		int balance = 0;
		for (int i = 0; i < N; ++i)
		{
			if (i % 2 == 0)
				balance += aliceValues[A[i].second];
			else
				balance -= bobValues[A[i].second];
		}
		if (balance == 0)
			return 0;
		if (balance < 0)
			return -1;
		return 1;
	}
};