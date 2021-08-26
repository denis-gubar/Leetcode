class Solution {
public:
    int uniqueMorseRepresentations( vector<string>& words ) {
        vector<string> codes{ ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
        set<string> result;
        for (const string& word : words)
        {
            string s;
            for (int w : word)
                s += codes[w - 'a'];
            result.insert( s );
        }
        return result.size();
    }
};