class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        vector<int> A(nums1), B(nums2);
        unordered_map<int, int> M, MA;
        for (int x : A)
            ++M[x], ++MA[x];
        for (int x : B)
            ++M[x];
        for (auto [key, value] : M)
        {
            if (value % 2 == 1)
                return -1;
            result += abs(value /2 - MA[key]);
        }
        return result / 2;
    }
};
