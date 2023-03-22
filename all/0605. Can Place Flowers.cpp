class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int N = flowerbed.size();
		for (int i = 0; n && i < N; ++i)
		{
		if (!flowerbed[i] && (!i || !flowerbed[i - 1]) && (i + 1 == N || !flowerbed[i + 1]))
			flowerbed[i] = 1, --n;
		}
		return n == 0;
	}
};