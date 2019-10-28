class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		vector<int> result(num1.size() + num2.size() - 1, 0);
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		for (int i = 0; i < num1.size(); ++i)
			for (int j = 0; j < num2.size(); ++j)
				result[i + j] += (num1[i] - '0') * (num2[j] - '0');
		int extra = 0;
		for (int i = 0; i < result.size(); ++i)
		{
			result[i] += extra;
			extra = result[i] / 10;
			result[i] %= 10;
		}
		while (extra)
		{
			result.push_back(extra % 10);
			extra /= 10;
		}
		string s;
		reverse(result.begin(), result.end());
		for (int i = 0; i < result.size(); ++i)
			s += result[i] + '0';
		return s;
	}
};