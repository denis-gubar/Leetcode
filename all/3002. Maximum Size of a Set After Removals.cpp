class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> M;
        for (int x : nums1)
            M[x] |= 1;
        for (int x : nums2)
            M[x] |= 2;
        int N = nums1.size() / 2;
        vector<int> A(4);
        for (auto [key, value] : M)
            ++A[value];
        return min(min(A[1], N) + min(A[2], N) + A[3], 2 * N);
    }
};
