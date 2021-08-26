class Solution {
public:
    string boldWords( vector<string>& words, string S ) {
        string result;
        vector<char> bold( S.size() );        
        for (int i = 0; i < S.size(); ++i)
            for (const string& word : words)
                if (word == S.substr( i, word.size() ))
                    for (int k = 0; k < word.size(); ++k)
                        bold[i + k] = 1;
        int isBold = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            if (bold[i] && !isBold)
            {
                result += "<b>";
                result += S[i];
                isBold = 1;
            }
            else if (!bold[i] && isBold)
            {
                result += "</b>";
                result += S[i];
                isBold = 0;
            }
            else
                result += S[i];
        }
        if (isBold)
            result += "</b>";
        return result;
    }
};