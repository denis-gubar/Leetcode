static int A[100'001][2];
static long long delta[100'001];
class Solution {
public:
    long long maxSubarrays(int N, vector<vector<int>>& conflictingPairs) {
        long long result = 0;
        int const P = conflictingPairs.size();
        memset(A, 1, sizeof(A));
        memset(delta, 0, sizeof(delta));
        for (int i = 0; i < P; ++i)
        {
            int const a = min(conflictingPairs[i][0], conflictingPairs[i][1]);
            int const b = max(conflictingPairs[i][0], conflictingPairs[i][1]);
            if (A[a][0] > b)
                A[a][1] = A[a][0], A[a][0] = b;
            else if (A[a][1] > b)
                A[a][1] = b;
        }
        int pos = N, HWM = A[0][0];
        for (int i = N; i >= 1; --i)
        {
            if (A[pos][0] > A[i][0])
                HWM = min(HWM, A[pos][0]), pos = i;
            else
                HWM = min(HWM, A[i][0]);
            result += min(A[pos][0], N + 1) - i;
            delta[pos] += min({ HWM, A[pos][1], N + 1 }) - min(A[pos][0], N + 1);
        }
        result += *max_element(&delta[0] + 1, &delta[0] + N + 1);
        return result;
    }
};

