class Solution {
public:
    int minimumSum(vector<int>& nums1, vector<int>& nums2) {
        int result = -1;
        int const N = nums1.size();
        unordered_map<int, int> M;
        for (int i = 0; i < N; ++i)
            if (M.find(nums1[i]) == M.end())
                M[nums1[i]] = i;
        for (int i = 0; i < N; ++i)
            if (auto it = M.find(nums2[i]); it != M.end())
            {
                result = (result == -1 || result > it->second + i) ? (it->second + i) : result;
                M.erase(it);
            }
        return result;
    }
};
