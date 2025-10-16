class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result;
        if (strs.empty())
            return result;
		for(int i = 0;; ++i)
		{
			for (const string& s : strs)
				if (s.size() == i || s[i] != strs[0][i])
					return result;
			result += strs[0][i];
		}
	}
};