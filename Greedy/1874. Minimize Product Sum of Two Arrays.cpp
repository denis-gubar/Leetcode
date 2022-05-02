class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end(), greater<int>{});
        return inner_product(nums1.begin(), nums1.end(), nums2.begin(), 0);
    }
};