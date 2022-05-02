class Solution {
public:
	string abbreviateProduct(int left, int right) {
		string result;
		long long total = 1;
		int zeroCount = 0;
		for (int i = left; i <= right; ++i)
		{
			total *= i;
			while (total % 10 == 0)
				total /= 10, ++zeroCount;
			if (total > 10'000'000'000LL)
				break;			
		}
		if (total < 10'000'000'000LL)
		{
			result = to_string(total) + "e" + to_string(zeroCount);
			return result;
		}
		total = 1;
		int d2 = 0, d5 = 0;
		int rest = 1;
		for (int i = left; i <= right; ++i)
		{
			int x = i;
			while (x % 2 == 0)
			{
				++d2;
				x /= 2;
			}
			while (x % 5 == 0)
			{
				++d5;
				x /= 5;
			}
			total *= x;
			while (total > 1'000'000'000'000LL)
				total /= 10;
			rest = 1LL * rest * x % 100'000;
		}
		zeroCount = min(d2, d5);
		while (d2 > zeroCount)
		{
			--d2;
			int x = 2;
			total *= x;
			while (total > 1'000'000'000'000LL)
				total /= 10;
			rest = 1LL * rest * x % 100'000;
		}
		while (d5 > zeroCount)
		{
			--d5;
			int x = 5;
			total *= x;
			while (total > 1'000'000'000'000LL)
				total /= 10;
			rest = 1LL * rest * x % 100'000;
		}
		string prefix = to_string(total);
		string suffix = to_string(100'000 + rest).substr(1);
		if (prefix.size() > 5)
			prefix = prefix.substr(0, 5);
		return prefix + "..." + suffix + "e" + to_string(zeroCount);
	}
};