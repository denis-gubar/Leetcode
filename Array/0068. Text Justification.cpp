class Solution {
public:
	string Justify(vector<string> const& words, int maxWidth, int length, bool isLast = false)
	{
		if (words.size() == 1)
			return words[0] + string(maxWidth - words[0].size(), ' ');
		vector<int> spaces(words.size() - 1, 1);
        if (!isLast)
        {
            int pos = 0;
            while (length < maxWidth)
            {
                ++spaces[pos];
                ++length;
                pos = (pos + 1) % spaces.size();
            }
        }
		string result{ words[0] };
		for (int i = 0; i < spaces.size(); ++i)
		{
			result += string(spaces[i], ' ');
			result += words[i + 1];
		}
        if (isLast)
            result += string(maxWidth - result.size(), ' ');
		return result;
	}
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		int length = 0, pos = 0;
		vector<string> buffer;
		while (pos < words.size())
		{
			if (length == 0)
			{
				length += words[pos].size();
				buffer.push_back(words[pos]);
				++pos;
			}
			else if (length + 1 + words[pos].size() <= maxWidth)
			{
				length += 1 + words[pos].size();
				buffer.push_back(words[pos]);
				++pos;
			}
			else
			{
				result.push_back(Justify(buffer, maxWidth, length));
				length = 0;
				buffer.clear();
			}
		}
        result.push_back(Justify(buffer, maxWidth, length, true));
		return result;
	}
};