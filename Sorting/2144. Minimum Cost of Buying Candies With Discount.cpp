class Solution {
public:
	int minimumCost(vector<int>& cost) {
		int result = 0;
		sort(cost.begin(), cost.end());
		while (cost.size() >= 3)
		{
			result += cost.back();
			cost.pop_back();
			result += cost.back();
			cost.pop_back();
			cost.pop_back();
		}
		for (int x : cost)
			result += x;
		return result;
	}
};

