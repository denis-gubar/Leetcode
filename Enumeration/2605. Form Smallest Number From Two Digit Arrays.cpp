class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int result = 99;
        for (int x = 1; x <= 9; ++x)
        {
            if (find(nums1.begin(), nums1.end(), x) != nums1.end() &&
                find(nums2.begin(), nums2.end(), x) != nums2.end())
                result = min(result, x);
            for (int y = 1; y <= 9; ++y)
                if (find(nums1.begin(), nums1.end(), x) != nums1.end() &&
                    find(nums2.begin(), nums2.end(), y) != nums2.end() ||
                    find(nums1.begin(), nums1.end(), y) != nums1.end() &&
                    find(nums2.begin(), nums2.end(), x) != nums2.end())
                    result = min(result, x * 10 + y);
        }
        return result;
    }
};
