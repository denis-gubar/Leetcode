class Solution {
public:
	vector<string> split(const string& s, char delimeter = '.')
	{
		vector<string> result;
		istringstream ss(s);
		for (string token; !ss.eof(); )
		{
			getline(ss, token, delimeter);
			result.push_back(token);
		}
		return result;
	}
	bool checkIp(string const& s)
	{
		vector<string> parts = split(s);
		if (parts.size() != 4)
			return false;
		for (string const& part : parts)
		{
			int x = atoi(part.c_str());
			if (to_string(x) != part || x > 255)
				return false;
		}
		return true;
	}
	void calc(string const& s, int pos, vector<int>& dotPositions)
	{
		if (dotPositions.size() == 3)
		{
			string r = s.substr(0, dotPositions[0]);
			for (int i = 1; i < 3; ++i)
			{
				r += '.';
				r += s.substr(dotPositions[i - 1], dotPositions[i] - dotPositions[i - 1]);
			}
			r += '.';
			r += s.substr(dotPositions[2]);
            if (checkIp(r))
			    result.push_back(r);
			return;
		}
		for (int nextPos = pos; nextPos < s.size(); ++nextPos)
		{
			dotPositions.push_back(nextPos);
			calc(s, nextPos + 1, dotPositions);
			dotPositions.pop_back();
		}
	}
	vector<string> restoreIpAddresses(string s) {
		result.clear();
        if (s.size() <= 12)
        {
            vector<int> dotPositions;
            calc(s, 1, dotPositions);
        }
		return result;
	}
	vector<string> result;
};