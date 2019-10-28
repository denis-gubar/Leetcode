class Solution {
public:
    string shortestCompletingWord( string licensePlate, vector<string>& words ) {
        transform( licensePlate.begin(), licensePlate.end(), licensePlate.begin(), ::tolower);
        licensePlate.erase( remove_if( licensePlate.begin(), licensePlate.end(), []( char c ) -> bool
                                    {
                                        return !isalpha( c );
                                    }
        ), licensePlate.end() );
        string result( 1001, '-' );
        for (const auto& word : words)
        {
            string s( licensePlate );
            for (const auto& ch : word)
            {
                int position = s.find( ch );
                if (position != string::npos)
                    s.erase( s.begin() + position );
            }
            if (s.empty())
            {
                if (word.size() < result.size())
                    result = word;
            }
        }
        return result;
    }
};