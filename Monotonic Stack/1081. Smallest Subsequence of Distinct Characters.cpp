class Solution {
public:
	string smallestSubsequence(string text) {
		if (text.size() < 2)
			return text;
		string s(text);
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		int numDistinct = s.size();
		vector<int> counts(128);
		int i = 0, distinct = 0;
		for (i = text.size() - 1; i >= 0; --i)
			if (++counts[text[i]] == 1)
			{
				if (++distinct == numDistinct)
					break;
			}
		string t = text.substr(0, i + 1);
		sort(t.begin(), t.end());
		string result;
		result += t[0];
		string newText;
		bool flag = true;
		for (char c : text)
			if (c == t[0])
				flag = false;
			else if (!flag)
				newText += c;
		result += smallestSubsequence(newText);
        return result;
	}
};