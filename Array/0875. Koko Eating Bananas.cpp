class Solution {
public:
	bool calc(int x)
	{
        if (!x)
            return false;
		int count = 0;
		for (int i = 0; i < piles.size(); ++i)
			count += (piles[i] + x - 1) / x;
		return count <= H;
	}
	vector<int> piles;
	int H;
	int minEatingSpeed(vector<int>& piles, int H) {
		this->H = H;
		this->piles = piles;
		int result = 1 << 30;
		int x = 1 << 29;
		for (int i = 29; i >= 0; --i)
			if (calc(x))
			{
				result = x;
				x -= 1 << i;
			}
			else
            	x += 1 << i;                
        if (calc(x))
            result = x;
		return result;
	}
};