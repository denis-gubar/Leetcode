class Solution {
public:
    string robotWithString(string s) {
        string result, t;
        int const N = s.size();
        result.reserve(N);
        t.reserve(N);
        vector<vector<int>> A(26);
        for (int i = 0; i < N; ++i)
            A[s[i] - 'a'].push_back(i);
        for (vector<int>& X : A)
            X.push_back(N);
        int pos = 0;
        for (int j = 0; j < 26; ++j)
        {
            while (!t.empty() && t.back() <= 'a' + j)
                result += t.back(), t.pop_back();
            while (true)
            {
                auto it = lower_bound(A[j].begin(), A[j].end(), pos);
                if (*it == N)
                    break;
                copy(s.begin() + pos, s.begin() + *it, back_inserter(t));
                pos = *it;
                ++pos;
                result += 'a' + j;
            }
        }
        while (!t.empty())
            result += t.back(), t.pop_back();
        return result;
    }
};
