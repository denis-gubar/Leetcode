class Solution {
public:
	int maxIceCream(vector<int>& costs, int coins) {
		sort(costs.begin(), costs.end());
		vector<long long> A;
		for (int i = 0; i < costs.size(); ++i)
		{
			if (!A.empty())
				A.push_back(A.back() + costs[i]);
			else
				A.push_back(costs[i]);
		}
		int result = lower_bound(A.begin(), A.end(), coins + 1) - A.begin();
		return result;
	}
};