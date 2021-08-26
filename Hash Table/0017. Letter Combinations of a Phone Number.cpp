class Solution {
public:
	void calc(const string& digits, string& prefix, vector<string>& result)
	{
		if (prefix.size() == digits.size())
		{
			result.push_back(prefix);
			return;
		}
		vector<string> M{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		int digit = digits[prefix.size()] - '0';
		for (char c : M[digit])
		{
			prefix.push_back(c);
			calc(digits, prefix, result);
			prefix.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		string prefix;
        if (!digits.empty())
		    calc(digits, prefix, result);
		return result;
	}
};