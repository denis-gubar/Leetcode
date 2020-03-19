class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        bool isSpace = true;
        string word;
        map<string, int> M;
        for(string& ban: banned)
            for(char& c: ban)
                c = ::tolower(c);
        paragraph += ' ';
        for(char c: paragraph)
        {
            if (isalpha(c))
            {
                word += ::tolower(c);
                isSpace = false;                
            }
            else
            {
                if (!word.empty() && find(banned.begin(), banned.end(), word) == banned.end())
                    ++M[word];
                word.clear();
                isSpace = true;
            }
        }
        string result;
        int best = 0;
        for(auto m: M)
            if (m.second > best)
            {
                best = m.second;
                result = m.first;
            }
        return result;
    }
};