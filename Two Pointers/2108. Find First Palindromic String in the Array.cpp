class Solution {
public:
	bool isPalindrome(string_view x)
	{
		int a = 0, b = x.size() - 1;
		while (a < b)
		{
			if (x[a] != x[b])
				return false;
			else
				++a, --b;
		}
		return true;
	}
	string firstPalindrome(vector<string>& words) {
		string result;
		for (string const& w : words)
			if (isPalindrome(w))
			{
				result = w;
				break;
			}
		return result;
	}
};