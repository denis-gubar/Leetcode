static int A[100'001][3];
static int B[100'001][3][3];
class Solution {
public:
    int longestBalanced(string s) {
        int result = 1;
        int const N = s.size();
        int count = 1;
        for (int i = 1; i < N; ++i)
            if (s[i - 1] == s[i])
                ++count, result = max(result, count);
            else
                count = 1;
        A[0][0] = A[0][1] = A[0][2] = 0;
        for (int i = 0; i < 3; ++i)
            B[0][i][0] = B[0][i][1] = B[0][i][2] = 0;
        auto encode = [](int a, int b, int c) -> long long
            {
                return ((a + 100'000LL) << 40LL) | ((b + 100'000LL) << 20LL) | (c + 100'000LL);
            };
        for (int i = 0; i < N; ++i)
            for (int c = 0, x = s[i] - 'a'; c < 3; ++c)
                A[i + 1][c] = A[i][c] + 2 * (c == x) - (c != x);
        for (int i = 0; i < N; ++i)
            for (int z = 0; z < 3; ++z)
                for (int c = 0, x = s[i] - 'a'; c < 3; ++c)
                    if (c != z)
                        B[i + 1][z][c] = B[i][z][c] + (c == x) - (c != x);
                    else
                        B[i + 1][z][c] = B[i][z][c] + (c == x);
        unordered_map<long long, int> M;
        M[encode(0, 0, 0)] = -1;
        for (int i = 0; i < N; ++i)
        {
            long long const hash = encode(A[i + 1][0], A[i + 1][1], A[i + 1][2]);
            if (auto it = M.find(hash); it != M.end())
                result = max(result, i - it->second);
            else
                M[hash] = i;
        }
        for (int z = 0; z < 3; ++z)
        {
            M.clear();
            M[encode(0, 0, 0)] = -1;
            for (int i = 0; i < N; ++i)
            {
                long long const hash = encode(B[i + 1][z][0], B[i + 1][z][1], B[i + 1][z][2]);
                if (auto it = M.find(hash); it != M.end())
                    result = max(result, i - it->second);
                else
                    M[hash] = i;
            }
        }
        return result;
    }
};
