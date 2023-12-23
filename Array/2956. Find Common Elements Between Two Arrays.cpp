class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result{ 0, 0 };
        set<int> S1(nums1.begin(), nums1.end());
        set<int> S2(nums2.begin(), nums2.end());
        for (int i = 0, N = nums1.size(); i < N; ++i)
            if (S2.find(nums1[i]) != S2.end())
                ++result[0];
        for (int i = 0, N = nums2.size(); i < N; ++i)
            if (S1.find(nums2[i]) != S1.end())
                ++result[1];
        return result;
    }
};
