class Solution {
public:
    string reverseVowels( string s ) {
        deque<char> t;
        auto isvowel = []( char c ) -> bool
            {
                return string( "aeuioAEUIO" ).find( c ) != string::npos;
            };
        copy_if( s.begin(), s.end(), front_inserter(t), isvowel );
        for (auto& c : s)
            if (isvowel( c ) )
            {
                c = t.front(); t.pop_front();
            }
        return s;
    }
};