class Solution {
public:
    string concat(string const& a, string const& b)
    {
        int A = a.size(), B = b.size();
        string result{ a + b };
        for (int start = 0; start < A; ++start)
        {
            if (A - start >= B)
            {
                if (equal(a.begin() + start, a.begin() + start + B, b.begin(), b.end()))
                    return a;
            }
            else
            {
                if (equal(a.begin() + start, a.end(), b.begin(), b.begin() + (A - start)))
                {
                    string t = a + b.substr(A - start);
                    if (t.size() < result.size() || t.size() == result.size() && t < result)
                        result = t;
                }
            }
        }
        return result;
    }
    string minimumString(string a, string b, string c) {
        string result = a + b + c;
        vector<string> S{a, b, c};
        sort(S.begin(), S.end());
        do
        {
            string t = concat(concat(S[0], S[1]), S[2]);
            if (t.size() < result.size() || t.size() == result.size() && t < result)
                result = t;
        } while (next_permutation(S.begin(), S.end()));
        return result;
    }
};
