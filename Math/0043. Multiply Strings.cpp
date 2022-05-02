class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") return "0";
		string result(num1.size() + num2.size() - 1, '0');
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int extra = 0;
		for (int i = 0; i < num1.size(); ++i)
		{
			int extra = 0;
			for (int j = 0; j < num2.size(); ++j)
			{
				extra = extra + (num1[i] - '0') * (num2[j] - '0') + (result[i + j] - '0');
				result[i + j] = '0' + extra % 10;
				extra /= 10;
			}
			if (extra)
			{
				if (i + 1 == num1.size())
					result += '0';
				result[i + num2.size()] += extra;
			}
		}
		reverse(result.begin(), result.end());
		return result;
	}
};