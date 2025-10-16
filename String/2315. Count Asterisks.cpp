class Solution {
public:
    vector<string> split(const string& s, char delimeter = '|')
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
    int countAsterisks(string s) {
        int result = 0;
        vector<string> S = split(s);
        int N = S.size();
        for (int i = 0; i < N; i += 2)
            result += count(S[i].begin(), S[i].end(), '*');
        return result;
    }
};
