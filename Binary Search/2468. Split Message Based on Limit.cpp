class Solution {
public:
	vector<string> split(string const& message, int limit, int maxParts)
	{
		vector<string> result;
		int count = 1;
		string suffix = "<" + to_string(count) + "/" + to_string(maxParts) + ">";
		int N = message.size();
		string buffer;
		for(int pos = 0; pos < N; ++pos)
		{
			if (buffer.size() + suffix.size() < limit)
				buffer += message[pos];
			else
			{
				if (buffer.empty())
					return {};
				result.push_back(buffer);
				result.back() += suffix;
				++count;
				if (count > maxParts)
					return {};
				buffer.clear();
				suffix = "<" + to_string(count) + "/" + to_string(maxParts) + ">";
				--pos;
				continue;
			}
		}
		if (buffer.empty())
			return {};
		result.push_back(buffer);
		result.back() += suffix;
		if (to_string(count).size() != to_string(maxParts).size())
			return {};
		for(string& s : result)
		{
			while(s.back() != '/')
				s.pop_back();
			s += to_string(count);
			s += '>';
		}
		return result;
	}
    vector<string> splitMessage(string message, int limit) {
        vector<string> result;
		int N = message.size();
		int maxParts = 9;
		while(true)
		{
			result = split(message, limit, maxParts);
			if (!result.empty())
				return result;
			if (maxParts >= N)
				break;
			maxParts = maxParts * 10 + 9;			
		}
		return result;
    }
};
