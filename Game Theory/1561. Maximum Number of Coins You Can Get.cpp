class Solution {
public:
	int maxCoins(vector<int>& piles) {
		sort(piles.begin(), piles.end());
		int result = 0;
		int N = piles.size();
		for (int i = N - 2, k = N / 3; k > 0; i -= 2, --k)
			result += piles[i];
		return result;
	}
};