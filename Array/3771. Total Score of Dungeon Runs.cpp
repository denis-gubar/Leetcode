static int A[100'002];
class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        long long result = 0;
        int const N = damage.size();
        vector<int> B(N + 1);
        A[0] = 0;
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + damage[i];
        A[N + 1] = A[N] + hp + 1;
        for (int i = 0; i < N; ++i)
        {
            if (hp - A[i + 1] >= requirement[i])
                ++B[0];
            else
            {
                auto it = lower_bound(&A[0], &A[0] + i + 1, A[i + 1] + requirement[i] - hp);
                ++B[it - &A[0]];
            }
            --B[i + 1];
        }
        int balance = 0;
        for (int i = 0; i < N; ++i)
            balance += B[i],
            result += balance;
        return result;
    }
};
