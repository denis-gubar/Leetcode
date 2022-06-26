class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        int A = accumulate(nums1.begin(), nums1.end(), 0);
        int B = accumulate(nums2.begin(), nums2.end(), 0);
        int result = max(A, B);
        vector<int> F(N + 1);
        set<int> S;
        for (int i = 0; i < N; ++i)
        {
            F[i + 1] = F[i] + nums2[i] - nums1[i];
            if (!S.empty())
            {
                int X = F[i + 1] - *S.begin();
                result = max(result, max(A + X, B - X));
                X = F[i + 1] - *S.rbegin();
                result = max(result, max(A + X, B - X));
            }
            S.insert(F[i + 1]);
        }
        return result;
    }
};
