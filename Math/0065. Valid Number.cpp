class Solution {
public:
    bool isNumber( string s ) {
        int a = 0;
        while (a < s.size() && s[a] == ' ')
            ++a;
        int b = s.size() - 1;
        while (b >= 0 && s[b] == ' ')
            --b;
        if (a > b)
            return false;
        s = s.substr( a, b - a + 1 );
        if (s == "." || s.substr(0, 2) == ".e" || s == "-." || s == "+." || s.substr(0, 3) == "-.e" || s.substr(0, 3) == "+.e")
            return false;
        if (s[0] == '-' || s[0] == '+')
            s = s.substr( 1 );
        if (s.empty() || !isdigit( s[0] ) && s[0] != '.')
            return false;
        while (!s.empty() && isdigit( s[0] ))
            s = s.substr( 1 );
        if (s.empty())
            return true;
        if (s[0] == '.')
            s = s.substr( 1 );
        while (!s.empty() && isdigit( s[0] ))
            s = s.substr( 1 );
        if (s.empty())
            return true;
        if (s[0] != 'e')
            return false;
        if (s[0] == 'e')
            s = s.substr( 1 );
        if (s.empty())
            return false;
        if (s[0] == '-' || s[0] == '+')
        {
            s = s.substr( 1 );
            if (s.empty())
                return false;
        }
        while (!s.empty() && isdigit( s[0] ))
            s = s.substr( 1 );
        return s.empty();
    }
};
