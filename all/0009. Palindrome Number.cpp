class Solution {
public:
	bool isPalindrome( int x ) {
		if (x == 0)
			return true;
        if (x < 0)
            return false;
		int t = x, k = 0;
		while (t)
		{
			t /= 10; ++k;
		}
		for (int i = 1; i + i <= k; ++i)
		{
			t = x;
			int j = 1;
			for (; j < i; ++j)
			{
				t /= 10;
			}
			int a = t % 10;
			for (;j <= k - i; ++j)
			{
				t /= 10;
			}
			int b = t % 10;
			if (a != b)
				return false;
		}

		return true;
	}
};