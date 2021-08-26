class Solution {
public:
	int maxCoins(vector<int>& piles) {
		sort(piles.begin(), piles.end());
		deque<int> Q(piles.begin(), piles.end());
		int result = 0;
		int N = piles.size() / 3;
		for (int i = 0; i < N; ++i)
		{
			Q.pop_back(); Q.pop_front();
			result += Q.back(); Q.pop_back();
		}
		return result;
	}
};