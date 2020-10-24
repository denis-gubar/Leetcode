class Solution {
public:
	string reorderSpaces(string text) {
		int spaceCount = 0;
		vector<string> words;
		string buffer;
		for (char c : text)
			if (c == ' ')
			{
				++spaceCount;
				if (!buffer.empty())
				{
					words.push_back(buffer);
					buffer.clear();
				}
			}
			else
				buffer += c;
        if (!buffer.empty())
            words.push_back(buffer);
		string result = words[0];
		int x = 0;
		if (words.size() > 1)
		{
			x = spaceCount / (words.size() - 1);
			spaceCount %= words.size() - 1;
		}
		for (int i = 1; i < words.size(); ++i)
		{
			result += string(x, ' ');
			result += words[i];
		}
		result += string(spaceCount, ' ');
		return result;
	}
};