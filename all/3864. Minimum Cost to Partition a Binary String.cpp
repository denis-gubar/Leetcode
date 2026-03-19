static int A[100'001];
class Solution {
public:
    long long calc(int left, int right)
    {
        long long const hash = (left << 20LL) | right;
        if (auto it = M.find(hash); it != M.end())
            return it->second;
        int const N = right - left + 1;
        int X = A[right + 1] - A[left];
        long long result = 1LL * X * N * encCost;
        if (X == 0)
            result = flatCost;
        if (N % 2 == 0)
        {
            long long L = calc(left, left + N / 2 - 1);
            long long R = calc(left + N / 2, right);
            if (L + R < result)
                result = L + R;
        }        
        return M[hash] = result;
    }
    long long minCost(string s, int encCost, int flatCost) {
        this->encCost = encCost;
        this->flatCost = flatCost;
        int const N = s.size();
        A[0] = 0;
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + (s[i] - '0');
        long long result = calc(0, N - 1);
        return result;
    }
    int encCost, flatCost;
    unordered_map<long long, long long> M;
};
