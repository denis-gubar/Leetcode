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
	string reformatDate(string date) {
		vector<string> S{ split(date) };
		vector<string> months{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		string result;
		result += S[2];
		result += '-';
		result += to_string(find(months.begin(), months.end(), S[1]) - months.begin() + 101).substr(1);
		result += '-';		
		if (isdigit(S[0][1]))
        {
            result += S[0][0];
			result += S[0][1];
        }
        else
        {
            result += '0';
            result += S[0][0];
        }
		return result;
	}
};