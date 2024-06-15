static int F[100'002][18];
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long result = 0;
        int N = nums.size();
        unordered_map<int, vector<int>> M;
        for (int i = 0; i < N; ++i)
            M[nums[i]].push_back(i);
        for (int i = 0; i < N; ++i)
            F[i][0] = nums[i];
        for (int j = 1; (1 << j) <= N; ++j)
            for (int i = 0, end = N - (1 << j); i <= end; ++i)
                F[i][j] = max(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
        auto rmq = [N](int L, int R)
            {
                if (L == R)
                    return F[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return max(F[L][j], F[R - (1 << j) + 1][j]);
            };
        for (auto const& [key, V] : M)
        {
            int const N = V.size();
            for (int start = 0; start < N; )
            {
                int length = 1;
                while (start + length < N && rmq(V[start], V[start + length]) == key)
                    ++length;
                start = start + length;
                result += 1LL * length * (length + 1) / 2;
            }
        }
        return result;
    }
};
