class Solution {
public:
	string toHex(unsigned int num) {
		string const digits{ "0123456789abcdef"s };
		string result;
		if (num == 0)
			result += '0';
		while (num)
		{
			result += digits[num % 16];
			num /= 16;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};