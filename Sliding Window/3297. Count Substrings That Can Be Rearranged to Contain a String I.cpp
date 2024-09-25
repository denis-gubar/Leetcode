class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        long long result = 0;
        vector<int> A(26), M(26);
        int const N = word1.size();
        int letterCount = 0;
        for (char c : word2)
            ++A[c - 'a'];
        for (int c = 0; c < 26; ++c)
            letterCount += A[c] > 0;
        int count = 0;
        auto add = [&A, &M, &count](char z)
            {
                int c = z - 'a';
                ++M[c];
                if (M[c] == A[c])
                    ++count;
            };
        auto remove = [&A, &M, &count](char z)
            {
                int c = z - 'a';
                if (M[c] == A[c])
                    --count;
                --M[c];
            };
        for (int R = 0, L = 0; R < N; ++R)
        {
            add(word1[R]);
            if (count < letterCount)
                continue;
            while (count == letterCount)
            {
                remove(word1[L]);
                ++L;
            }
            --L;
            add(word1[L]);
            result += L + 1;
        }
        return result;
    }
};
