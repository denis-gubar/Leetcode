class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int N = nums.size();
        int result = 0;
        int M[200'001];
        memset(M, 0, sizeof(M));
        for (int x : nums)
            ++M[x];
        int current = 0;
        for (int i = 0; i <= 2 * k; ++i)
            current += M[i];
        result = max(result, current);
        for (int i = k + 1; i + k <= 100'000; ++i)
        {
            current -= M[i - k - 1];
            current += M[i + k];
            result = max(result, current);
        }
        return result;
    }
};
