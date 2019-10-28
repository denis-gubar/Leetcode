class Solution {
public:
	string addStrings(string num1, string num2) {
		string result;
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int position = 0, extra = 0;
		while (position < num1.size() || position < num2.size())
		{
			int digit = extra;
			if (position < num1.size())
				digit += num1[position] - '0';
			if (position < num2.size())
				digit += num2[position] - '0';
			extra = digit / 10;
			digit %= 10;
			result += digit + '0';
            ++position;
		}
		if (extra)
			result += extra + '0';
		reverse(result.begin(), result.end());
		return result;
	}
};