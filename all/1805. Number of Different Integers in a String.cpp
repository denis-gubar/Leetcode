class Solution {
public:
	int numDifferentIntegers(string word) {
		unordered_set<string> S;
		string s;
        word += '$';
		for (char c : word)
			if (isdigit(c))
				s += c;
			else
			{
				if (!s.empty())
				{
					reverse(s.begin(), s.end());
					while (s.size() > 1 && s.back() == '0')
						s.pop_back();
					reverse(s.begin(), s.end());
					S.insert(s);
					s.clear();
				}
			}
		return S.size();
	}
};