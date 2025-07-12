static short F[100'000];
class Solution {
public:
    short calc(string const& a, string const& b)
    {
        short result = 0;
        for (short end = min(a.size(), b.size()); result < end; ++result)
            if (a[result] != b[result])
                break;
        return result;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int const N = words.size();
        vector<int> result(N);
        if (N < 3)
            return result;
        memset(F, 0, sizeof(F));
        multiset<short> S;
        for (int i = 1; i < N; ++i)
        {
            F[i - 1] = calc(words[i - 1], words[i]);
            S.insert(F[i - 1]);
        }
        vector<short> A, B;
        for (int i = 0; i < N; ++i)
        {
            if (i > 0)
                A.push_back(F[i - 1]), S.erase(S.find(F[i - 1]));
            if (i < N - 1)
                A.push_back(F[i]), S.erase(S.find(F[i]));
            if (i > 0 && i < N - 1)
                B.push_back(calc(words[i - 1], words[i + 1])), S.insert(B.back());
            result[i] = *prev(S.end());
            for (short x : B)
                S.erase(S.find(x));
            for (short x : A)
                S.insert(x);
            A.clear(), B.clear();
        }
        return result;
    }
};
