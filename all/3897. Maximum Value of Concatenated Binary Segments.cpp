static int const MOD = 1'000'000'007;
class Solution {
public:
    struct Binary
    {
        int zeroCount;
        int oneCount;
        friend bool operator< (Binary L, Binary R)
        {
            if (L.oneCount == 0 || R.oneCount == 0)
                return L.oneCount < R.oneCount;
            if (L.zeroCount == 0 || R.zeroCount == 0)
                return L.zeroCount > R.zeroCount;
            return pair<int, int>{L.oneCount, -L.zeroCount} < pair<int, int>{R.oneCount, -R.zeroCount};
        }
    };
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int result = 0;
        int const N = nums1.size();
        vector<Binary> A;
        A.reserve(N);
        for (int i = 0; i < N; ++i)
            A.emplace_back(nums0[i], nums1[i]);
        sort(A.begin(), A.end());
        auto add = [](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
            };
        for (int i = N - 1; i >= 0; --i)
        {
            Binary const& B = A[i];
            for (int k = 0; k < B.oneCount; ++k)
                add(result, result + 1);
            for (int k = 0; k < B.zeroCount; ++k)
                add(result, result);
        }
        return result;
    }
};
