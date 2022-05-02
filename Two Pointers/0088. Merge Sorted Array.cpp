class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = m - 1, b = n - 1, i = n + m - 1;
        while(i >= 0)
        {
            if (a < 0 || b >= 0 && nums1[a] < nums2[b])
                nums1[i--] = nums2[b--];
            else if (b < 0 || a >= 0 && nums2[b] < nums1[a])
                nums1[i--] = nums1[a--];
            else
            {
                nums1[i--] = nums2[b--];
                nums1[i--] = nums1[a--];
            }
        }
    }
};