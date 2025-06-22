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
    string generateTag(string caption) {
        string result;
        string t;
        vector<string> S = split(caption);
        for (int i = 0; i < S.size(); ++i)
        {
            string s = S[i];
            for (char& c : s)
                c = ::tolower(c);
            if (!t.empty())
                s[0] = ::toupper(s[0]);
            t += s;
        }
        result += '#';
        for (char c : t)
            if ('a' <= c && c <= 'z' || !'A' <= c && c <= 'Z')
                result += c;
        if (result.size() > 100)
            result = result.substr(0, 100);
        return result;
    }
};
