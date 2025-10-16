static int const MOD = 1'000'000'007;
static unsigned int A[26];
template<size_t SIZE, typename T>
struct TransformationMatrix
{
    T Matrix[SIZE * SIZE];
    TransformationMatrix()
    {
        zero(Matrix);
    }
    void zero(T* A)
    {
        memset(A, 0, sizeof(T) * SIZE * SIZE);
    }
    void identity(T* A)
    {
        zero(A);
        for (unsigned int i = 0; i < SIZE; ++i)
            A[i * SIZE + i] = 1;
    }
    void copy(T* result, T* const A)
    {
        memcpy(result, A, sizeof(T) * SIZE * SIZE);
    }
    void multiply(T* result, T* const A, T* const B)
    {
        for (unsigned int i = 0; i < SIZE; ++i)
        {
            T* c = result + i * SIZE;
            for (unsigned int j = 0; j < SIZE; ++j)
                c[j] = 0;
            for (unsigned int k = 0; k < SIZE; ++k)
            {
                T* const b = B + k * SIZE;
                T const a = A[i * SIZE + k];
                for (unsigned int j = 0; j < SIZE; ++j)
                    c[j] = (c[j] + 1LL * a * b[j]) % MOD;
            }
        }
    }
    void multiplyVector(T* result, T* const A, T* const B)
    {
        memset(result, 0, sizeof(T) * SIZE);
        for (int r = 0; r < SIZE; ++r)
            for (int c = 0; c < SIZE; ++c)
                //result[r] += A[r * SIZE + c] * B[r];
                result[r] = (result[r] + 1ULL * A[r * SIZE + c] * B[r]) % MOD;
    }
    void power(T* result, size_t N)
    {
        if (N == 0)
        {
            identity(result);
            return;
        }
        if (N == 1)
        {
            copy(result, Matrix);
            return;
        }
        T A[SIZE * SIZE];
        T temp[SIZE * SIZE];
        copy(A, Matrix);
        identity(result);
        while (N)
        {
            if (N & 1)
            {
                multiply(temp, result, A);
                copy(result, temp);
            }
            multiply(temp, A, A);
            copy(A, temp);
            N >>= 1;
        }
    }
};
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        TransformationMatrix<26, unsigned int> TM;
        memset(A, 0, sizeof(A));
        for (char c : s)
            ++A[c - 'a'];
        for (int c = 0; c < 26; ++c)
            for (int x = 1; x <= nums[c]; ++x)
                ++TM.Matrix[c * 26 + (c + x) % 26];
        long long result = 0;
        unsigned int R[26 * 26];
        TM.zero(R);
        TM.power(R, t);
        unsigned int B[26];
        TM.multiplyVector(B, R, A);
        for (int c = 0; c < 26; ++c)
            result += B[c];
        return result % MOD;
    }
};
