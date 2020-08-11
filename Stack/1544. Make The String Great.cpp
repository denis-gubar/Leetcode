class Solution {
public:
	string makeGood(string s) {
		string result(s);
		bool flag = true;
		while (flag)
		{
			flag = false;
			string t(result);
            result = "";
			int i = 0;
			for (; i + 1 < t.size(); ++i)
				if (tolower(t[i]) == tolower(t[i + 1]) && t[i] != t[i + 1])
					++i, flag = true;
				else
					result += t[i];
			if (i < t.size())
				result += t[i];
		}
		return result;
	}
};