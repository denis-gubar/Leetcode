class Solution {
public:
	int shipWithinDays(vector<int>& weights, int D) {
		int a = 0, b = accumulate(weights.begin(), weights.end(), 0);
		int result = b;
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			vector<int> x{ 0 };
			bool check = true;
			for (int w : weights)
			{
				if (w > m)
				{
					check = false; break;
				}
				if (x.back() + w > m)
				{
					x.push_back(w);
				}
				else
					x.back() += w;
			}
			if (check && x.size() <= D)
			{
				b = m;
				result = m;
			}
			else
			{
				a = m;
			}
		}
		return result;
	}
};