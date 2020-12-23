class Solution {
public:
	string interpret(string command) {
		vector<pair<string, string>> A{ {"G","G"}, {"()", "o"}, {"(al)", "al" } };
		string result;
		for (int i = 0; i < command.size(); ++i)
		{
			for (auto const& p : A)
				if (command.substr(i, p.first.size()) == p.first)
				{
					result += p.second;
					break;
				}
		}
		return result;
	}
};