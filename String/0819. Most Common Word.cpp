class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		string result, word;
		bool isSpace = true;
		sort(banned.begin(), banned.end());
        for(string& ban: banned)
            for(char& c: ban)
                c = tolower(c);
		map<string, int> count;
		paragraph += ' ';
		for (char c : paragraph)
		{
			if (isalpha(c))
			{
				word += tolower(c);
				isSpace = false;
			}
			else 
			{
                if (!word.empty() && !binary_search(banned.begin(), banned.end(), word))
				    ++count[word];
                word.clear();
                isSpace = true;				
			}
		}
		int best = 0;
		for(auto m: count)
			if (best < m.second)
			{
				best = m.second;
				result = m.first;
			}
		return result;
	}
};