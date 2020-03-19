class Solution {
public:
	vector<string> split(const string& s, char delimeter = ' ')
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
	string validIPAddress(string IP) {
		if (IP.find('.') != string::npos)
		{
			vector<string> S = split(IP, '.');
			if (S.size() != 4)
				return "Neither";
			vector<int> X(4);
			for (int i = 0; i < S.size(); ++i)
			{
                if (S[i].size() > 3)
                    return "Neither";
				for (char c : S[i])
					if (!isdigit(c))
						return "Neither";
					else
						X[i] = X[i] * 10 + (c - '0');
                if (X[i] > 255)
                    return "Neither";
			}
			if (to_string(X[0]) + '.' + to_string(X[1]) + '.' + to_string(X[2]) + '.' + to_string(X[3]) != IP)
				return "Neither";
			return "IPv4";
		}
		else if (IP.find(':') != string::npos)
		{
			vector<string> S = split(IP, ':');
			if (S.size() != 8)
				return "Neither";
			for (int i = 0; i < 8; ++i)
			{
				if (S[i].size() > 4 || S[i].size() == 0)
					return "Neither";
				for (char c : S[i])
					if (!isdigit(c) && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F'))
						return "Neither";
			}
			return "IPv6";
		}
		return "Neither";
	}
};