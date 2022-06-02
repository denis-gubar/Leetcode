class Solution {
public:
    vector<string> split(const string& s, char delimeter = ' ')
    {
        vector<string> result;
        istringstream ss(s);
        for (string token; !ss.eof(); )
        {
            getline(ss, token, delimeter);
            result.push_back(token);
        }
        return result;
    }
    string discountPrices(string sentence, int discount) {
        string result;
        vector<string> S = split(sentence);
        int N = S.size();
        for (int i = 0; i < N; ++i)
        {
            bool is$ = false;
            string t = S[i];
            if (S[i][0] == '$')
            {
                t = t.substr(1);
                if (count(t.begin(), t.end(), '.') <= 1 && !t.empty())
                {
                    is$ = true;
                    for (char c : t)
                        is$ &= (c == '.' || isdigit(c));
                    if (is$)
                    {
                        long long x = stod(t) * (100 - discount) * 2 + 1;
                        x /= 2;
                        t = to_string(x / 100) + '.' + to_string(x % 100 + 100).substr(1);
                    }
                }         
            }
            if (!result.empty())
                result += ' ';
            if (!is$)
            {
                result += S[i];
            }
            else
            {
                result += '$';
                result += t;
            }
        }
        return result;
    }
};
