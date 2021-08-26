class Solution {
public:
    int minimumLengthEncoding( vector<string>& words ) {
        int result = 0, wordCount = 0;
        sort( words.begin(), words.end(), []( const string& a, const string& b )->bool
              {
                  return a.size() > b.size();
              } );
        set<string> S;
        for (const string& w : words)
        {
            if (S.find( w ) == S.end())
            {
                ++wordCount;
                result += w.size();
                for (int i = 0; i < w.size(); ++i)
                    S.insert( w.substr( i ) );
            }
        }
        result += wordCount;
        return result;
    }
};