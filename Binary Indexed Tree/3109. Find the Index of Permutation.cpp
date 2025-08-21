static int mergeBuffer[2'000'000];
static int const MOD = 1'000'000'007;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int const N = nums.size();
        vector<int> result(N);
        iota(&mergeBuffer[0], &mergeBuffer[0] + N, 0);
        int offset = N;
        auto mergeSort = [&offset, &result, &nums](this const auto& self, int first, int last) -> void
            {
                int const N = last - first;
                if (N < 2)
                    return;
                int const F = offset;
                memcpy(&mergeBuffer[0] + F, &mergeBuffer[0] + first, sizeof(mergeBuffer[0]) * N);
                offset += N;
                self(F, F + N / 2);
                self(F + N / 2, F + N);
                int L = F;
                int R = F + N / 2;
                for (int i = first; i < last; ++i)
                {
                    if (R == F + N || L != F + N / 2 && nums[mergeBuffer[L]] <= nums[mergeBuffer[R]])
                        mergeBuffer[i] = mergeBuffer[L], result[mergeBuffer[L]] += R - (F + N / 2), ++L;
                    else
                        mergeBuffer[i] = mergeBuffer[R], ++R;
                }
            };
        mergeSort(0, N);
        return result;
    }
    int getPermutationIndex(vector<int>& perm) {
        int result = 0;
        vector<int> A = countSmaller(perm);
        int const N = perm.size();
        for (int i = 0, fact = 1; i < N; ++i)
        {
            result = (result + 1LL * fact * A[N - 1 - i]) % MOD;
            fact = 1LL * fact * (i + 1) % MOD;
        }
        return result;
    }
};
