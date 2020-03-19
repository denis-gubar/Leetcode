class Solution {
public:
	string freqAlphabets(string s) {
		string result;
		vector<pair<string, string>> rules;
		for (int c = 'j', k = 10; c <= 'z'; ++c, ++k)
			rules.push_back({ to_string(k) + "#", string(1, c) });
		for (int c = 'a'; c <= 'i'; ++c)
			rules.push_back({ string(1, c + ('1' - 'a')), string(1, c) });
		for (int pos = 0; pos < s.size();)
			for (auto& rule : rules)
				if (s.find(rule.first, pos) == pos)
				{
					result += rule.second;
					pos += rule.first.size();
					break;
				}
		return result;
	}
};
