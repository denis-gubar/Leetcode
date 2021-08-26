class Solution {
public:
    string reverseWords( string s ) {
        string result;
        istringstream ss( s );
        while (!ss.eof())
        {
            string t;
            ss >> t;
            reverse( t.begin(), t.end() );
            if (result.empty())
                result = t;
            else
                result += " " + t;
        }
        return result;
    }
};