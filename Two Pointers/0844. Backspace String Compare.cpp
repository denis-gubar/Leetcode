class Solution {
public:
	string calc(string S)
	{
		string result;
		for (char c : S)
			if (c != '#')
				result += c;
			else
				if (!result.empty())
					result.pop_back();
		return result;
	}
	bool backspaceCompare(string S, string T) {
		return calc(S) == calc(T);
	}
};