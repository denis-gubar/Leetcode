class Solution {
public:
	vector<string> generatePossibleNextMoves(string s) {
		vector<string> result;
		for(int i = 1; i < s.size(); ++i)
			if (s[i] == '+' && s[i - 1] == '+')
			{
				string current(s);
				current[i] = '-'; current[i - 1] = '-';
				result.push_back(current);
			}
		return result;
	}
};