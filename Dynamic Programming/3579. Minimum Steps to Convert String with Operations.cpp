using INT = unsigned char;
static INT A[100][100];
static INT F[101];
class Solution {
public:
    int minOperations(string word1, string word2) {
        INT const N = word1.size();
        INT result = 0;
        memset(A, 0, sizeof(A));
        auto hash = [](INT a, INT b) -> unsigned short
            {
                return (a << 8) | b;
            };
        for (int i = 0; i < N; ++i)
        {
            unordered_map<unsigned short, INT> M;
            unsigned short count = 0;
            unsigned short swapCount = 0;
            for (int j = i; j < N; ++j)
            {
                A[i][j] = j - i + 1;
                if (word1[j] != word2[j])
                {
                    if (auto it = M.find(hash(word2[j], word1[j])); it != M.end())
                    {
                        ++swapCount;
                        --count;
                        if (--it->second == 0)
                            M.erase(it);
                    }
                    else
                    {
                        ++count;
                        ++M[hash(word1[j], word2[j])];
                    }
                }
                A[i][j] = min<INT>(A[i][j], count + swapCount);
            }
        }
        string R;
        R.reserve(N);
        for (int i = 0; i < N; ++i)
        {
            for (int j = i; j < N; ++j)
                if (A[i][j] > 0)
                {
                    unordered_map<unsigned short, INT> M;
                    unsigned short count = 0;
                    unsigned short swapCount = 0;
                    R.clear();
                    for (int z = j; z >= i; --z)
                        R += word1[z];
                    for (int z = i; z <= j; ++z)
                    {
                        if (R[z - i] != word2[z])
                        {
                            if (auto it = M.find(hash(word2[z], R[z - i])); it != M.end())
                            {
                                ++swapCount;
                                --count;
                                if (--it->second == 0)
                                    M.erase(it);
                            }
                            else
                            {
                                ++count;
                                ++M[hash(R[z - i], word2[z])];
                            }
                        }
                    }
                    A[i][j] = min<INT>(A[i][j], 1 + count + swapCount);
                }
        }
        memset(F, N, sizeof(F));
        F[0] = 0;
        for (INT j = 0; j < N; ++j)
            for (INT i = 0; i <= j; ++i)
                F[j + 1] = min<INT>(F[j + 1], F[i] + A[i][j]);
        return F[N];
    }
};
