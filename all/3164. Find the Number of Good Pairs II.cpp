static long long F[1'000'001];
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> M;
        int const MAX = *max_element(nums1.begin(), nums1.end());
        for (int x : nums2)
        {
            int key = x * k;
            if (key <= MAX)
                ++M[x * k];
        }
        memset(F, 0, sizeof(F));
        for (auto [key, value] : M)
            for (int i = key; i <= MAX; i += key)
                F[i] += value;
        long long result = 0;
        for (int x : nums1)
            result += F[x];
        return result;
    }
};
