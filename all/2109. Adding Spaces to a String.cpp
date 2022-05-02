class Solution {
public:
	string addSpaces(string s, vector<int>& spaces) {
		string result;
		int N = s.size(), M = spaces.size();
		int i = 0, j = 0;
		while (i < N || j < M)
		{
			if (j < M && spaces[j] == i)
			{
				result += ' ';
				++j;
				continue;
			}
			result += s[i];
			++i;
		}
		return result;
	}
};