class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        vector<int> A;
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(A));
        if (A.empty())
            return -1;
        return A[0];
    }
};
