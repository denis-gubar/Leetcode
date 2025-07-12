static vector<string> const LINES{ "electronics", "grocery", "pharmacy", "restaurant" };
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int const N = code.size();
        vector<int> I;
        vector<string> result;
        I.reserve(N);
        result.reserve(N);
        for (int i = 0; i < N; ++i)
        {
            bool isGood = !code[i].empty() && isActive[i];
            for (char c : code[i])
                isGood &= ::isdigit(c) || ::isalpha(c) || c == '_';
            isGood &= find(LINES.begin(), LINES.end(), businessLine[i]) != LINES.end();
            if (isGood)
                I.push_back(i);
        }
        sort(I.begin(), I.end(), [&](int a, int b)
            {
                if (find(LINES.begin(), LINES.end(), businessLine[a]) - LINES.begin() != find(LINES.begin(), LINES.end(), businessLine[b]) - LINES.begin())
                    return find(LINES.begin(), LINES.end(), businessLine[a]) - LINES.begin() < find(LINES.begin(), LINES.end(), businessLine[b]) - LINES.begin();
                return code[a] < code[b];
            });
        for (int i = 0; i < I.size(); ++i)
            result.push_back(code[I[i]]);
        return result;
    }
};
