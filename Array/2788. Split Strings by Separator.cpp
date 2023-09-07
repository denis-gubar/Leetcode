class Solution {
public:
    vector<string> split(const string& s, char delimeter = ' ')
    {
        vector<string> result;
        istringstream ss(s);
        for (string token; !ss.eof(); )
        {
            getline(ss, token, delimeter);
            if (!token.empty())
                result.push_back(token);
        }
        return result;
    }
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;
        for (string const& w : words)
        {
            vector<string> A = split(w, separator);
            copy(A.begin(), A.end(), back_inserter(result));
        }
        return result;
    }
};
