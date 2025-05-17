static char F[101][101];
static char A[601][2];
class Solution {
public:
    int findMaxForm(vector<string>& strs, int zeroes, int ones) {
        int const N = strs.size();
        memset(A, 0, sizeof(A));
        for (int i = 0; i < N; ++i)
            for (char c : strs[i])
                ++A[i][c - '0'];
        auto update = [](char& x, char value)
            {
                if (x < value)
                    x = value;
            };
        memset(F, 0, sizeof(F));
        for (int k = 0; k < N; ++k)
            for (int i = zeroes; i >= 0; --i)
                for (int j = ones; j >= 0; --j)
                    if (i + A[k][0] <= zeroes && j + A[k][1] <= ones)
                        update(F[i + A[k][0]][j + A[k][1]], F[i][j] + 1);
        return F[zeroes][ones];
    }
};
