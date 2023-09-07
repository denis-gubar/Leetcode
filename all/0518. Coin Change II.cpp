static int F[5'002];
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		int N = coins.size();
		memset(F, 0, sizeof(F));
		F[0] = 1;
		for (int j = 0; j < N; ++j)
			for (int i = 0; i + coins[j] <= amount; ++i)
				F[i + coins[j]] += F[i];
		return F[amount];
	}
};