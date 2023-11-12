class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        int result = N + 1;        
        int current = 0;
        for (int k = 0; k < 2; ++k)
        {
            int a = nums1.back(), b = nums2.back();
            for (int i = 0; i < N - 1; ++i)
            {
                if (nums1[i] <= a && nums2[i] <= b)
                    continue;
                if (nums1[i] <= b && nums2[i] <= a)
                {
                    ++current;
                    continue;
                }
                current = N + 1;
                break;
            }
            swap(nums1.back(), nums2.back());
            result = min(result, current);
            current = 1;
        }
        if (result > N)
            result = -1;
        return result;
    }
};
