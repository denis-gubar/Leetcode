class Solution {
public:
	bool areSentencesSimilar(string sentence1, string sentence2) {
		string s = " " + sentence1 + " ", t = " " + sentence2 + " ";
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == ' ')
				for (int j = i; j < s.size(); ++j)
					if (s[j] == ' ')
					{
						string x = s.substr(0, i) + s.substr(j);
						if (x == t)
							return true;
					}
		swap(s, t);
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == ' ')
				for (int j = i; j < s.size(); ++j)
					if (s[j] == ' ')
					{
						string x = s.substr(0, i) + s.substr(j);
						if (x == t)
							return true;
					}
		return false;
	}
};