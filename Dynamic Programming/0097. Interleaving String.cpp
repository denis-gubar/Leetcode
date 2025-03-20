static bool F[102][102];
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int const A = s1.size(), B = s2.size(), C = s3.size();
        if (A + B != C)
            return false;
        memset(F, 0, sizeof(F));
        F[0][0] = true;
        for (int i = 0; i <= A; ++i)
            for (int j = 0; j <= B; ++j)
                if (F[i][j])
                {
                    F[i + 1][j] |= s1[i] == s3[i + j];
                    F[i][j + 1] |= s2[j] == s3[i + j];
                }
        return F[A][B];
    }
};
