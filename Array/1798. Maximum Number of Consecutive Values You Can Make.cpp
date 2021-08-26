class Solution {
public:
	int getMaximumConsecutive(vector<int>& coins) {
		sort(coins.begin(), coins.end());
		int result = 0;
		for (int coin : coins)
			if (coin <= result + 1)
				result += coin;
		return result + 1;
	}
};