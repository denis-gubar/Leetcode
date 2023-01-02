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
    bool isCircularSentence(string sentence) {
        vector<string> S = split(sentence);
        int N = S.size();
        for (int i = 0; i < N; ++i)
            if (S[i].back() != S[(i + 1) % N][0])
                return false;
        return true;
    }
};
