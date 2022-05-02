class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string result;
        vector<int> M(26);
        for (char c : s)
            ++M[c - 'a'];
        vector<pair<int, int>> S;
        for (int i = 0; i < 26; ++i)
            if (M[i])
                S.push_back({ i + 'a', M[i]});
        int last = '$';
        while (!S.empty())
        {            
            if (last != S.back().first)
            {
                auto& [letter, count] = S.back();
                last = letter;
                int delta = min(count, repeatLimit);
                if (count == delta)
                    S.pop_back();
                else
                    count -= delta;
                result += string(delta, letter);
            }
            else
            {
                if (S.size() == 1)
                    break;
                auto& [letter, count] = S[S.size() - 2];
                last = letter;
                result += letter;
                if (count == 1)
                {
                    S[S.size() - 2] = S.back();
                    S.pop_back();
                }
                else
                    --count;
            }
        }
        return result;
    }
};
