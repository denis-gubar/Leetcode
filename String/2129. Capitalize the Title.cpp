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
    string capitalizeTitle(string title) {
        string result;
        vector<string> S{ split(title) };
        for (int i = 0; i < S.size(); ++i)
        {
            string t = S[i];
			for (char& c : t)
				c = ::tolower(c);
            if (t.size() >= 3)
                t[0] = ::toupper(t[0]);
            result += t;
            if (i + 1 < S.size())
                result += ' ';
        }
        return result;
    }
};
