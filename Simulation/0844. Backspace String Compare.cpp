class Solution {
public:
	string calc(string const& s)
	{
		string result;
		for (char c : s)
			if (c == '#')
			{
				if (!result.empty())
					result.pop_back();
			}
			else
				result += c;
		return result;
	}
	bool backspaceCompare(string S, string T) {
		return calc(S) == calc(T);
	}
};