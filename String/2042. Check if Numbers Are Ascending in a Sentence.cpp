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
	bool areNumbersAscending(string s) {
		int last = 0;
		vector<string> A(split(s));
		for (string const& x : A)
			if (isdigit(x[0]))
			{
				int current = stoi(x);
				if (current > last)
					last = current;
				else
					return false;
			}
		return true;
	}
};