class Solution {
public:
	string calc(vector<int> const& digits)
	{
		if (digits.empty()) return {};
		string result;
		if (digits[0] > 0)
			for (int d : digits)
				result += '0' + d;
		else
			result = "0";
		return result;
	}
	string largestMultipleOfThree(vector<int>& digits) {
		sort(digits.begin(), digits.end());
		reverse(digits.begin(), digits.end());
		vector<int> count(10);
		int rest = 0;
		for (int d : digits)
		{
			++count[d];
			rest += d;
		}
		rest %= 3;
		if (rest == 0)
			return calc(digits);
		if (rest == 1)
		{
			if (count[1] > 0)
			{
				digits.erase(find(digits.begin(), digits.end(), 1));
				return calc(digits);
			}
			if (count[4] > 0)
			{
				digits.erase(find(digits.begin(), digits.end(), 4));
				return calc(digits);
			}
			if (count[7] > 0)
			{
				digits.erase(find(digits.begin(), digits.end(), 7));
				return calc(digits);
			}
			for (int toDelete = 0; toDelete < 2; ++toDelete)
			{
				if (count[2]-- > 0)
				{
					digits.erase(find(digits.begin(), digits.end(), 2));
					continue;
				}
				if (count[5]-- > 0)
				{
					digits.erase(find(digits.begin(), digits.end(), 5));
					continue;
				}
				if (count[8]-- > 0)
				{
					digits.erase(find(digits.begin(), digits.end(), 8));
					continue;
				}
			}
            return calc(digits);
		}
		if (count[2] > 0)
		{
			digits.erase(find(digits.begin(), digits.end(), 2));
			return calc(digits);
		}
		if (count[5] > 0)
		{
			digits.erase(find(digits.begin(), digits.end(), 5));
			return calc(digits);
		}
		if (count[8] > 0)
		{
			digits.erase(find(digits.begin(), digits.end(), 8));
			return calc(digits);
		}
		for (int toDelete = 0; toDelete < 2; ++toDelete)
		{
			if (count[1]-- > 0)
			{
				digits.erase(find(digits.begin(), digits.end(), 1));
				continue;
			}
			if (count[4]-- > 0)
			{
				digits.erase(find(digits.begin(), digits.end(), 4));
				continue;
			}
			if (count[7]-- > 0)
			{
				digits.erase(find(digits.begin(), digits.end(), 7));
				continue;
			}
		}
		return calc(digits);
	}
};