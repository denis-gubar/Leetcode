class Solution {
public:
	int countConsistentStrings(string allowed, vector<string>& words) {
		int result = 0;
		for (string const& w : words)
		{
			bool flag = true;
			for (char c : w)
				if (allowed.find(c) == string::npos)
					flag = false;
			result += flag;
		}
		return result;
	}
};