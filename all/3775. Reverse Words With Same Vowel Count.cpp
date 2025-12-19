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
    string reverseWords(string s) {
        string const vowels = "aeiou";
        string result;
        result.reserve(s.size());
        vector<string> S = split(s);
        int vowelCount = 0;
        for (char c : S[0])
            vowelCount += vowels.find(c) != string::npos;
        result += S[0];
        int const N = S.size();
        for (int i = 1; i < N; ++i)
        {
            int count = 0;
            for (char c : S[i])
                count += vowels.find(c) != string::npos;
            if (count == vowelCount)
                reverse(S[i].begin(), S[i].end());
            result += ' ';
            result += S[i];
        }
        return result;
    }
};
