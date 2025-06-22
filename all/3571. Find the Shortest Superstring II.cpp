class Solution {
public:
    string shortestSuperstring(string s1, string s2) {
        string result = s1 + s2;
        string_view a(s1), b(s2);
        if (s1.find(s2) != string::npos)
            return s1;
        if (s2.find(s1) != string::npos)
            return s2;
        int const A = s1.size(), B = s2.size();
        for (int length = min(A, B); length > 0; --length)
        {
            if (a.substr(A - length, length) == b.substr(0, length))
            {
                if (result.size() > A + B - length)
                    result = s1 + s2.substr(length, B - length);
                break;
            }
            if (b.substr(B - length, length) == a.substr(0, length))
            {
                if (result.size() > A + B - length)
                    result = s2 + s1.substr(length, A - length);
                break;
            }
        }
        return result;
    }
};
