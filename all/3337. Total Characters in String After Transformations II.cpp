static int const MOD = 1'000'000'007;
static int A[26];
static int M[26][26];
static int R[26][26];
static void multiply(int arr1[26][26], int arr2[26][26])
{
    int arr3[26][26];
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
        {
            arr3[i][j] = 0;
            for (int k = 0; k < 26; ++k)
                arr3[i][j] = (arr3[i][j] + 1LL * arr1[i][k] * arr2[k][j]) % MOD;
        }
    memcpy(arr1, arr3, 4 * 26 * 26);
}
static void power(int M[26][26], int N)
{
    int A[26][26];
    memcpy(A, M, 4 * 26 * 26);
    memset(R, 0, sizeof(R));
    for (int i = 0; i < 26; ++i)
        R[i][i] = 1;

    while (N) 
    {
        if (N & 1)
            multiply(R, A);
        multiply(A, A);
        N >>= 1;
    }
}
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        memset(A, 0, sizeof(A));
        for (char c : s)
            ++A[c - 'a'];
        memset(M, 0, sizeof(M));
        auto add = [](int& x, int y)
            {
                x += y;
                if (x >= MOD)
                    x -= MOD;
            };
        for (int c = 0; c < 26; ++c)
            for (int x = 1; x <= nums[c]; ++x)
                ++M[c][(c + x) % 26];
        long long result = 0;
        power(M, t);
        for (int c = 0; c < 26; ++c)
            for (int nc = 0; nc < 26; ++nc)
                result += 1LL * R[c][nc] * A[c];
        return result % MOD;
    }
};
