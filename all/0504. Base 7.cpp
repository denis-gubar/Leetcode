class Solution {
public:
	string convertToBase7(int num) {
		string result;
		string sign;
		if (num < 0)
			sign = "-", num = -num;
		else if (num == 0)
			result += '0';
		while (num)
		{
			result += num % 7 + '0';
			num /= 7;
		}
		result += sign;
		reverse(result.begin(), result.end());
		return result;
	}
};