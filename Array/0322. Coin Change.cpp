class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> M(amount + 1, amount + 1);
		M[0] = 0;
		for (int c : coins)
			for (int i = 0; i + c <= amount; ++i)
				M[i + c] = min(M[i + c], M[i] + 1);
		if (M.back() == amount + 1)
			return -1;
		return M.back();
	}
};