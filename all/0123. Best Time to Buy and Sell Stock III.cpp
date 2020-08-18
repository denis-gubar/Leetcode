class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int have0 = numeric_limits<int>::min();
		int have1 = numeric_limits<int>::min();
		int sold0 = 0;
		int sold1 = 0;
		for (int p : prices)
		{
			int newHave0 = max(have0, -p);
			int newSold0 = max(sold0, have0 + p);
			int newHave1 = max(have1, sold0 - p);
			int newSold1 = max(sold1, have1 + p);
            have0 = newHave0, sold0 = newSold0, have1 = newHave1, sold1 = newSold1;
		}
		return max(sold0, sold1);
	}
};