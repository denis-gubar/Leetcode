class Solution {
public:
	bool isThree(int n) {
		for(int x = 2; x * x <= n; ++x)
			if (n % x == 0)
			{
				if (x * x < n)
					return false;
				return true;
			}
		return false;
	}
};