class Solution {
public:
    int numberOfSubstrings(string s, int K) {
        int const N = s.size();
        if (K == 1)
            return N * (N + 1) / 2;
        int result = 0;
        vector<int> A(26);
        for (int L = 0, R = 0, count = 0; R < N; )
        {
            auto add = [&A, K, &count, &s](int i)
                {
                    if (++A[s[i] - 'a'] == K)
                        ++count;
                };
            auto remove = [&A, K, &count, &s](int i)
                {
                    if (--A[s[i] - 'a'] == K - 1)
                        --count;
                };
            add(R), ++R;
            if (count == 0)
                continue;
            while (count > 0)
                remove(L), ++L;
            --L, add(L);
            result += L + 1;
        }
        return result;
    }
};
