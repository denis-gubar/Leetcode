static int F[20'002][4];
static short P[20'002][4];
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int K) {
        vector<int> result(3);
        int const N = nums.size();
        vector<int> A;
        A.reserve(N - K + 1);
        int sum = 0;
        for (int i = 0; i < K; ++i)
            sum += nums[i];
        A.push_back(sum);
        for (int i = K; i < N; ++i)
        {
            sum += nums[i] - nums[i - K];
            A.push_back(sum);
        }
        memset(F, -1, sizeof(F));
        memset(P, 125, sizeof(P));
        F[0][0] = 0;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < 4; ++j)
                if (F[i][j] >= 0)
                {
                    if (F[i + 1][j] < F[i][j])
                        F[i + 1][j] = F[i][j], P[i + 1][j] = P[i][j];
                    else if (F[i + 1][j] == F[i][j])
                        P[i + 1][j] = min<short>(P[i + 1][j], P[i][j]);
                    if (j < 3 && i + K <= N && F[i + K][j + 1] < F[i][j] + A[i])
                        F[i + K][j + 1] = F[i][j] + A[i], P[i + K][j + 1] = i;
                }
        for (int i = N, j = 3; j > 0; i = P[i][j], --j)
            result[j - 1] = P[i][j];
        return result;
    }
};
