class Solution {
public:
	string toHexspeak(string num) {
		string result;
		string digits("OI--------ABCDEF");
		long long N = atoll(num.c_str());
		while (N)
		{
			result += digits[N % 16LL];
			N /= 16LL;
		}
		reverse(result.begin(), result.end());
		if (result.find('-') != string::npos)
			return "ERROR";
		return result;
	}
};