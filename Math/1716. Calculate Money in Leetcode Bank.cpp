class Solution {
public:
	int totalMoney(int n) {
		int result = 0;
		int x = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i % 7 == 0) ++x;
			result += (i % 7) + x;
		}
		return result;
	}
};