static int F1[500][9];
static int F2[500][9];
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int Q = l.size();
        vector<bool> result(Q);
        memset(F1, 0, sizeof(F1));
        memset(F2, 0, sizeof(F2));
        int N = nums.size();
        for (int i = 0; i < N; ++i)
            F1[i][0] = F2[i][0] = nums[i];
        for (int j = 1; (1 << j) <= N; ++j)
            for (int i = 0, end = N - (1 << j); i <= end; ++i)
            {
                F1[i][j] = min(F1[i][j - 1], F1[i + (1 << (j - 1))][j - 1]);
                F2[i][j] = max(F2[i][j - 1], F2[i + (1 << (j - 1))][j - 1]);
            }
        auto rmq1 = [](int L, int R)
            {
                if (L == R)
                    return F1[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return min(F1[L][j], F1[R - (1 << j) + 1][j]);
            };
        auto rmq2 = [](int L, int R)
            {
                if (L == R)
                    return F2[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return max(F2[L][j], F2[R - (1 << j) + 1][j]);
            };
        for (int q = 0; q < Q; ++q)
        {
            int const& left = l[q];
            int const& right = r[q];
            int a = rmq1(left, right);
            int b = rmq2(left, right);
            if (a == b)
            {
                result[q] = true;
                continue;
            }
            if ((b - a) % (right - left) != 0)
                continue;
            int delta = (b - a) / (right - left);
            unordered_set<int> S;
            result[q] = true;
            for (int i = left; i <= right; ++i)
                if ((nums[i] - a) % delta != 0 || !S.insert((nums[i] - a) / delta).second)
                {
                    result[q] = false;
                    break;
                }                
        }
        return result;
    }
};
