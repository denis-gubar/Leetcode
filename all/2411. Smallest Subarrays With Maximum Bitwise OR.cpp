class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<vector<int>> A(31);
        int N = nums.size();
        vector<int> result(N);
        for (int i = 0; i < N; ++i)
        {
            for (int k = 0; k < 31; ++k)
                if ((nums[i] & (1 << k)) > 0)
                    A[k].push_back(i);
        }
        auto get = [&A](int a, int b)
        {
            int result = 0;
            for (int k = 0; k < 31; ++k)
            {
                auto it = lower_bound(A[k].begin(), A[k].end(), a);
                if (it != A[k].end() && *it <= b)
                    result |= 1 << k;
            }
            return result;
        };
        for (int i = 0; i < N; ++i)
        {
            int x = get(i, N - 1);
            int b = i;
            for (int k = 0; k < 31; ++k)
            {
                if ((x & (1 << k)) > 0)
                    b = max(b, *lower_bound(A[k].begin(), A[k].end(), i));
            }
            result[i] = b - i + 1;
        }
        return result;
    }
};
